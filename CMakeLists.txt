cmake_minimum_required(VERSION 3.14)
project(KickAss C)

set(CMAKE_C_STANDARD 11)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

add_executable(KickAss main.c tools/string.h tools/vector.h systems/output/output.h systems/output/sprite.h collections/safe_array.h collections/iteration.h collections/list.h collections/map.h hyper_c/concatenation.h hyper_c/macros.h hyper_c/definition.h hyper_c/usage.h hyper_c.h systems/input/input.h game.h character.h systems/placing/position.h systems/movement/movement.h systems/movement/movable.h control.h systems/collision/collision.h systems/collision/collider.h tools/math.h systems/attack/attacking.h systems/attack/attack.h systems/generation/generation.h systems/ai/ai.h systems/health/health.h systems/health/health_system.h systems/sound/sound.h)

target_link_libraries(KickAss m)
target_link_libraries(KickAss ${SDL2_LIBRARIES})