# Build output setup
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/test/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/test/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/test/bin)

################################
# GTest
################################
project(googletest-git NONE)

include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        v1.13.0
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
set(BUILD_GMOCK OFF CACHE BOOL "" FORCE)
set(BUILD_GTEST ON CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(googletest)

################################
# Tests
################################
# All libraries to test
set(LIBS_TO_TEST
  lib_structs
)
set(TEST_FILES
    tuple_tests.cpp
    color_tests.cpp
    canvas_tests.cpp
    matrix_tests.cpp
    transformation_tests.cpp
    ray_sphere_tests.cpp
    intersections.cpp
)
# Add test cpp file
add_executable(${TESTNAME} ${TEST_FILES})
# Link test executable against gtest & gtest_main
target_link_libraries(${TESTNAME} gtest gtest_main ${LIBS_TO_TEST})
