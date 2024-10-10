cmake_minimum_required(VERSION 3.10)

project(day6)

add_subdirectory(makeFrame)

link_directories(${CMAKE_SOURCE_DIR}/lib)
include_directories(${CMAKE_SOURCE_DIR}/day6/makeFrame/)

# find_package(jsoncpp)
# if(jsoncpp_FOUND)
#     message("INFO: we found Libjsoncpp on your pc.")
#     message(jsoncpp_FOUND = ${jsoncpp_FOUND})
#     message(jsoncpp_INCLUDE_DIR = ${jsoncpp_INCLUDE_DIR}) 
#     message(jsoncpp_LIBRARY = ${jsoncpp_LIBRARY})
# else(jsoncpp_FOUND)
#     message("WARNING: we couldn't find Libjsoncpp on your pc. DLC is disabled.")
# endif(jsoncpp_FOUND)

aux_source_directory(./ SRC_FILES)
add_executable(${PROJECT_NAME} ${SRC_FILES})

target_link_libraries(${PROJECT_NAME} makeFrame)
target_link_libraries(${PROJECT_NAME} jsoncpp)