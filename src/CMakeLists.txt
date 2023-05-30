# Build output setup
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/src/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/src/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/src/bin)

add_executable(${PROJECT_NAME} main.cpp)

add_subdirectory(structs)

set(ALL_SUBLIBRARIES
    lib_structs
)
set(ALL_DEPENDENCIES

)

target_link_libraries(${PROJECT_NAME} PRIVATE ${ALL_SUBLIBRARIES} PUBLIC ${ALL_DEPENDENCIES})
