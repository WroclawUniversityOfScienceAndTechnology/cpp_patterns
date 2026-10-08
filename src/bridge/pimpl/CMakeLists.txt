cmake_minimum_required(VERSION 3.14)

project(pimpl LANGUAGES CXX)

add_executable(${PROJECT_NAME}
    pimpl.cpp
    person.cpp
)

