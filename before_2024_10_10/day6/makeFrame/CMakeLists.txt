cmake_minimum_required(VERSION 3.10)

project(makeFrame)

aux_source_directory(. SRC_FILES)
add_library(${PROJECT_NAME} SHARED ${SRC_FILES})