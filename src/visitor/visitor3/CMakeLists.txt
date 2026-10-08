
cmake_minimum_required(VERSION 3.14)

project(visitor3 LANGUAGES CXX)

file(GLOB SRC_FILES ${PROJECT_SOURCE_DIR}/*.cpp)

add_executable(${PROJECT_NAME}
    ${SRC_FILES}
)