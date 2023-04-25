cmake_minimum_required(VERSION 3.25)
project(rt-playground-cpp)

set(CMAKE_CXX_STANDARD 20)


add_library(render_hit STATIC ./src/render/render.cpp ./src/structs/hit.cpp)

add_executable(playground_main ./src/main.cpp)
target_link_libraries(playground_main LINK_PUBLIC render_hit)
