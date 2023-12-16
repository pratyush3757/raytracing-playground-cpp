set(LIB_EXTRA_SRC
    rt_cannon.cpp)

add_library(lib_extra
    ${LIB_EXTRA_SRC}
)

target_include_directories(lib_extra PUBLIC .)
