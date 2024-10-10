cmake_minimum_required(VERSION 3.10)

project(serialize_json)

set(CXX_STANDARD_REQUIRED ON)
set(CXX_STANDARD 11)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/inc/third_part)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/inc/common_struct)

file(GLOB_RECURSE SRC_FILES ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)

add_executable(${PROJECT_NAME} ${SRC_FILES})