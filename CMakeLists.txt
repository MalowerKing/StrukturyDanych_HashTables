cmake_minimum_required(VERSION 3.4)
project(Nowak_Projekt_Hash_Table)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/build/bin/$<CONFIG>")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/build/lib/$<CONFIG>")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/build/lib/$<CONFIG>")

include_directories(include)

file(GLOB_RECURSE SOURCES 
        "*.cpp"
        "*.cc")

add_executable(resoult main.cpp ${HEADERS})
