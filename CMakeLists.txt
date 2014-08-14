cmake_minimum_required (VERSION 2.4)

project (LIBBENARYORG)

file(GLOB_RECURSE files_cpp ${LIBBENARYORG_SOURCE_DIR}/*.cpp) 
add_library ( benaryorg SHARED ${files_cpp} ) 

INSTALL(TARGETS benaryorg
	RUNTIME DESTINATION /usr/bin
	LIBRARY DESTINATION /usr/lib
	ARCHIVE DESTINATION /usr/lib
)
