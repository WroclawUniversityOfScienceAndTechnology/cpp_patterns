# This is the only custom build layer; pwrforge update generates the root project.
# The generated x86 Conan profile forces the legacy libstdc++ ABI. Use the
# compiler's default ABI here to match the Ubuntu system libraries we link.
remove_definitions(-D_GLIBCXX_USE_CXX11_ABI=0)

# PATTERN_EXAMPLE comes from [project.cmake-variables] in pwrforge.toml.
if(DEFINED ENV{EXAMPLE} AND NOT "$ENV{EXAMPLE}" STREQUAL "")
    set(PATTERN_EXAMPLE "$ENV{EXAMPLE}")
endif()
if(NOT DEFINED PATTERN_EXAMPLE)
    set(PATTERN_EXAMPLE "decorator/decorator1")
endif()

if(NOT PATTERN_EXAMPLE MATCHES "^[a-zA-Z0-9_]+/[a-zA-Z0-9_]+$"
   OR NOT EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/${PATTERN_EXAMPLE}/CMakeLists.txt")
    message(FATAL_ERROR "Choose an example with a CMakeLists.txt, e.g. decorator/decorator1")
endif()

set(pattern_binary_name "${PROJECT_NAME}")
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/${PATTERN_EXAMPLE}" "examples/${PATTERN_EXAMPLE}")
get_property(example_targets DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/${PATTERN_EXAMPLE}"
             PROPERTY BUILDSYSTEM_TARGETS)
set(example_executables "")
foreach(example_target IN LISTS example_targets)
    get_target_property(target_type "${example_target}" TYPE)
    if(target_type STREQUAL "EXECUTABLE")
        list(APPEND example_executables "${example_target}")
    endif()
endforeach()
list(LENGTH example_executables executable_count)
if(NOT executable_count EQUAL 1)
    message(FATAL_ERROR "${PATTERN_EXAMPLE} must define exactly one executable")
endif()
list(GET example_executables 0 example_target)

# Keep the selected executable in its own directory. The standard pwrforge bin
# directory contains one stable entry point for pwrforge run and pwrforge debug.
set_target_properties("${example_target}" PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/examples/${PATTERN_EXAMPLE}")
add_custom_target(selected_example ALL
    COMMAND "${CMAKE_COMMAND}" -E make_directory "${CMAKE_BINARY_DIR}/bin"
    COMMAND "${CMAKE_COMMAND}" -E copy_if_different
            "$<TARGET_FILE:${example_target}>"
            "${CMAKE_BINARY_DIR}/bin/${pattern_binary_name}.elf"
    DEPENDS "${example_target}"
    VERBATIM
)
message(STATUS "Selected example: ${PATTERN_EXAMPLE} (${example_target})")
