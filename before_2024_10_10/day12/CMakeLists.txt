cmake_minimum_required(VERSION 3.10)

project(ipmpil)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/IPMPIL)

link_directories(${CMAKE_SOURCE_DIR}/lib)

add_subdirectory(IPMPIL)

aux_source_directory(. SRC_FILES)
add_executable(${PROJECT_NAME} ${SRC_FILES})

target_link_libraries(${PROJECT_NAME} weight)