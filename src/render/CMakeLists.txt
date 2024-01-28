set(LIB_RENDER_SRC
    ppm.cpp)

add_library(lib_render
    ${LIB_RENDER_SRC}
)

target_include_directories(lib_render PUBLIC .)
