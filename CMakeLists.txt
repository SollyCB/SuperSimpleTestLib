cmake_minimum_required(VERSION 3.2)
project(exe)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED true)
set(CMAKE_BUILD_TYPE DEBUG)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}")
set(CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS} ${GCC_COVERAGE_LINK_FLAGS}")

set(GCC_COVERAGE_COMPILE_FLAGS "-std=c++17" "-ggdb")

set(SOURCE_FILES main.cpp thing.cpp)
add_executable(exe ${SOURCE_FILES})

target_compile_options(exe PRIVATE "${GCC_COVERAGE_COMPILE_FLAGS}")
target_link_libraries(exe PRIVATE "${GCC_COVERAGE_LINK_FLAGS}")

target_include_directories(exe PUBLIC "${PROJECT_BINARY_DIR}" )

option(BUILD_TESTS ON)
if(BUILD_TESTS)
    message("Hello")
    add_compile_definitions(TESTS)
    add_executable(
        test_all
        test.cpp
        thing_test.cpp
        thing.cpp
    )
endif()
