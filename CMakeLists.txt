cmake_minimum_required(VERSION 3.14)
project(KickAss C)

set(CMAKE_C_STANDARD 11)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

add_executable(KickAss main.c tools/string.h tools/vector.h sdl.h sprite.h collections/safe_array.h collections/iteration.h collections/list.h collections/map.h hyper_c/concatenation.h hyper_c/macros.h hyper_c/definition.h hyper_c/usage.h hyper_c.h)

target_link_libraries(KickAss ${SDL2_LIBRARIES})