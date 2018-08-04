cmake_minimum_required(VERSION 3.5)

project(uBoy)

set(SOURCES 
	src/main.c
	src/memory.c
	src/instructions.c
	src/timer.c
	src/debug.c
	src/opcodes.c
	src/cbopcodes.c
	src/test.c
)

add_executable(uBoy ${SOURCES})

target_include_directories(uBoy
    PRIVATE 
        ${PROJECT_SOURCE_DIR}/include
)
