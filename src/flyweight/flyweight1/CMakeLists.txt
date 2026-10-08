cmake_minimum_required(VERSION 3.14)

project(flyweight1 LANGUAGES CXX)

# boost need to be install first: 
# sudo apt-get install cmake libblkid-dev e2fslibs-dev libboost-all-dev libaudit-dev
find_package(Boost 1.71 REQUIRED system serialization)
# include_directories(${Boost_INCLUDE_DIR})

set(Boost_USE_STATIC_LIBS ON) 
set(Boost_USE_MULTITHREADED ON)  
set(Boost_USE_STATIC_RUNTIME OFF) 
set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

add_executable(${PROJECT_NAME}
    flyweight1.cpp
)

target_link_libraries(${PROJECT_NAME} 
    ${Boost_PROGRAM_OPTIONS_LIBRARY} 
    ${Boost_REGEX_LIBRARY} 
    ${Boost_LIBRARIES}
    Threads::Threads
)
