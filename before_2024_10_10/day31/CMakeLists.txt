cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 11)

project(future)

file(GLOB_RECURSE SRC_FILES *.cpp)

add_executable(${PROJECT_NAME}  ${SRC_FILES})

target_link_libraries(${PROJECT_NAME} -lpthread)