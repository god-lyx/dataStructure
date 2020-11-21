cmake_minimum_required(VERSION 3.0.0)
project(sqlist VERSION 0.1.0)

add_library(sqlist_library STATIC sqlist.cpp)

target_include_directories(sqlist_library PUBLIC ${PROJECT_SOURCE_DIR})

add_executable(sqlist_binary main.cpp)

target_link_libraries(sqlist_binary sqlist_library)

