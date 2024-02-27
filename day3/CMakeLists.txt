cmake_minimum_required(VERSION 3.10)

project(day3)

add_subdirectory(text)

include_directories(${CMAKE_SOURCE_DIR}/day3/text/)
link_directories(${CMAKE_SOURCE_DIR}/lib)

aux_source_directory(. SRC_FILES)
add_executable(${PROJECT_NAME} ${SRC_FILES})

target_link_libraries(${PROJECT_NAME} testA)