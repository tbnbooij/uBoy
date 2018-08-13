cmake_minimum_required(VERSION 3.5)
project(uBoy)

set(SOURCES 
	src/main.c
	src/cpu.c
	src/state.c
	src/memory.c
	src/instructions.c
	src/debug.c
	src/ppu.c
)

add_executable(uBoy ${SOURCES})

target_include_directories(uBoy
    PRIVATE 
        ${PROJECT_SOURCE_DIR}/include
)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})
target_link_libraries(uBoy ${SDL2_LIBRARIES})