cmake_minimum_required(VERSION 3.14)
project(composite_ex LANGUAGES CXX)

add_executable(${PROJECT_NAME}
    composite_ex.cpp
)

target_link_libraries(${PROJECT_NAME}
    gtest
    gtest_main
    pthread
)

enable_testing()

target_link_libraries(${PROJECT_NAME} gtest gtest_main)
add_test( ${PROJECT_NAME} runUnitTests )