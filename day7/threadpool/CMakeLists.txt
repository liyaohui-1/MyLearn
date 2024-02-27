cmake_minimum_required(VERSION 3.10)

project(threadpool)

aux_source_directory(. SRC_FILES)
add_library(${PROJECT_NAME} ${SRC_FILES})

target_link_libraries(${PROJECT_NAME} pthread)