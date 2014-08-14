cmake_minimum_required (VERSION 2.4)

project (LIBBENARYORG)

file(GLOB_RECURSE files ${LIBBENARYORG_SOURCE_DIR}/*.c) 
add_library ( benaryorg SHARED ${files} ) 

INSTALL(TARGETS benaryorg
	RUNTIME DESTINATION /usr/bin
	LIBRARY DESTINATION /usr/lib
	ARCHIVE DESTINATION /usr/lib
)
