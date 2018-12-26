project(konbini/tests/shared_lib)

add_library(stublib MODULE stublib.cpp)
add_executable(testapp main.cpp)