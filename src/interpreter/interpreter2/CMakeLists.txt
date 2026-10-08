cmake_minimum_required(VERSION 3.14)

project(proxy4 LANGUAGES CXX)

# boost need to be install first: 
# sudo apt-get install -y libcpprest-dev
find_package(Boost 1.71 REQUIRED system serialization)
# include_directories(${Boost_INCLUDE_DIR})
find_package(cpprestsdk REQUIRED)

set(Boost_USE_STATIC_LIBS ON) 
set(Boost_USE_MULTITHREADED ON)  
set(Boost_USE_STATIC_RUNTIME OFF) 

add_executable(${PROJECT_NAME}
    proxy4.cpp
)

target_link_libraries(${PROJECT_NAME} 
    ${Boost_PROGRAM_OPTIONS_LIBRARY} 
    ${Boost_REGEX_LIBRARY} 
    ${Boost_LIBRARIES}
    cpprestsdk::cpprest
)
