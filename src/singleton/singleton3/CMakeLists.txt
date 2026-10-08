cmake_minimum_required(VERSION 3.14)

project(singleton3 LANGUAGES CXX)

# boost need to be install first: 
# sudo apt-get install cmake libblkid-dev e2fslibs-dev libboost-all-dev libaudit-dev
find_package(Boost 1.71 REQUIRED system serialization)
# include_directories(${Boost_INCLUDE_DIR})

set(Boost_USE_STATIC_LIBS ON) 
set(Boost_USE_MULTITHREADED ON)  
set(Boost_USE_STATIC_RUNTIME OFF) 

add_executable(${PROJECT_NAME}
    singleton.cpp
)

target_link_libraries(${PROJECT_NAME} 
    ${Boost_PROGRAM_OPTIONS_LIBRARY} 
    ${Boost_REGEX_LIBRARY} 
    ${Boost_LIBRARIES}

    gtest
    gtest_main
    pthread
)

enable_testing()

target_link_libraries(${PROJECT_NAME} gtest gtest_main)
add_test( ${PROJECT_NAME} runUnitTests )