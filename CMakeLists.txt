cmake_minimum_required(VERSION 3.25)

set(TESTNAME "test_runner")
project(rt-playground-cpp)

set(CMAKE_CXX_STANDARD 20)
# set(CMAKE_CXX_CLANG_TIDY
#   clang-tidy;
#   -checks=-*;
#   -format-style='llvm';
#   -header-filter=${CMAKE_CURRENT_SOURCE_DIR};
# )
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_subdirectory(src)

# build tests
project(${TESTNAME})

enable_testing()

add_subdirectory(test)

add_test(NAME ${TESTNAME}
        COMMAND ${TESTNAME}
)
