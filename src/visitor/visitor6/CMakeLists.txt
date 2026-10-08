
cmake_minimum_required(VERSION 3.14)

project(visitor6 LANGUAGES CXX)

file(GLOB SRC_FILES ${PROJECT_SOURCE_DIR}/*.cpp)
set(CMAKE_CXX_STANDARD 17)

add_executable(${PROJECT_NAME}
    ${SRC_FILES}
)