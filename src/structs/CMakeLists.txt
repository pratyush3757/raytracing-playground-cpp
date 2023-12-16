set(LIB_STRUCTS_SRC
    rt_tuples.cpp)

add_library(lib_structs
    ${LIB_STRUCTS_SRC}
)

target_include_directories(lib_structs PUBLIC .)
