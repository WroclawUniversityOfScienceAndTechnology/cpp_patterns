cmake_minimum_required(VERSION 3.14)

project(iterator1 LANGUAGES CXX)

# boost need to be install first: 
# sudo apt-get install cmake libblkid-dev e2fslibs-dev libboost-all-dev libaudit-dev libc++-dev
find_package(Boost 1.71 REQUIRED system serialization)
# include_directories(${Boost_INCLUDE_DIR})
# set(CMAKE_CXX_STANDARD 20)
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fcoroutines-ts")

set(Boost_USE_STATIC_LIBS ON) 
set(Boost_USE_MULTITHREADED ON)  
set(Boost_USE_STATIC_RUNTIME OFF) 
set(THREADS_PREFER_PTHREAD_FLAG ON)

add_executable(${PROJECT_NAME}
    iterator1.cpp
)

target_link_libraries(${PROJECT_NAME} 
    ${Boost_PROGRAM_OPTIONS_LIBRARY} 
    ${Boost_REGEX_LIBRARY} 
    ${Boost_LIBRARIES}
)
