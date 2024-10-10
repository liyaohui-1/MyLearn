cmake_minimum_required(VERSION 3.10)

project(mytest)
message(STATUS "PROJECT_NAME = ${PROJECT_NAME}")

add_compile_options(-w)

set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 11)

set(CMAKE_BUILD_TYPE debug)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/output)

if(NOT DEFINED ENV{TEST_CODE})  
    # 如果没有设置，则可以选择一个默认值或抛出一个错误  
    message(STATUS "TEST_CODE environment variable must be set")
else()
    message(STATUS "TEST_CODE environment variable seted = ${TEST_CODE}")
    if(TEST_CODE STREQUAL "2")
      message(STATUS "TEST_CODE set 2!")
      add_definitions(-DTEST_CODE=2)
    elseif(TEST_CODE STREQUAL "1")
      message(STATUS "TEST_CODE set 1!")
      add_definitions(-DTEST_CODE=1)
    else()
      message(STATUS "TEST_CODE not set!")
    endif() 
endif() 

aux_source_directory(. SRC_FILES)

add_executable(${PROJECT_NAME} ${SRC_FILES})

target_link_libraries(${PROJECT_NAME} pthread)