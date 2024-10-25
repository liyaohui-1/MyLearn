cmake_minimum_required(VERSION 3.10)

project(sem_com)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/)

set(rd rd.c sem.c)
set(wr wr.c sem.c)

add_executable(rd ${rd})
add_executable(wr ${wr})