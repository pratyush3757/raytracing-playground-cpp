set(LIB_STRUCTS_SRC
    rt_tuples.cpp
    rt_matrix.cpp
    rt_transformations.cpp
    rt_util.cpp
)

add_library(lib_structs
    ${LIB_STRUCTS_SRC}
)

target_include_directories(lib_structs PUBLIC .)
