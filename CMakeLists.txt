cmake_minimum_required(VERSION 3.25)

set(TESTNAME "test_runner")
project(rt-playground-cpp)

set(CMAKE_CXX_STANDARD 20)
add_subdirectory(src)

# build tests
project(${TESTNAME})

enable_testing()

add_subdirectory(test)

add_test(NAME ${TESTNAME}
        COMMAND ${TESTNAME}
)
