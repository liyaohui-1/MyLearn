cmake_minimum_required(VERSION 3.10)

project(day7)

add_subdirectory(threadpool)

include_directories(${CMAKE_SOURCE_DIR}/day7/threadpool)
link_directories(${CMAKE_SOURCE_DIR}/lib)

aux_source_directory(. SRC_FILES)
add_executable(${PROJECT_NAME} ${SRC_FILES})

target_link_libraries(${PROJECT_NAME} threadpool)