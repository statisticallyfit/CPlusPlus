cmake_minimum_required(VERSION 3.3)
project(BoostTutorial)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES chi_square_std_dev_test.cpp)
add_executable(BoostTutorial ${SOURCE_FILES})