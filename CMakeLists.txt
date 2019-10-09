cmake_minimum_required(VERSION 2.6)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
add_library(writer writer.cpp)
add_library(logger logger.cpp)

# Link runTests with what we want to test and the GTest and pthread library
add_executable(runTests main.cpp)

target_link_libraries(runTests ${GTEST_LIBRARIES} writer logger pthread)