cmake_minimum_required (VERSION 2.6)

project (LIBBENARYORG)

file(GLOB_RECURSE files_cpp ${LIBBENARYORG_SOURCE_DIR}/*.cpp) 
add_library ( benaryorg SHARED ${files_cpp} ) 
