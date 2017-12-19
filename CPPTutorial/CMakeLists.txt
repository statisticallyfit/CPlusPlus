cmake_minimum_required(VERSION 3.2)
project(C__Tutorial)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES cpp/bookOOPC++/chapter10_Pointers/ex12_FloatPointerClass.cpp
        #chapter10_Pointers/StringUsingNew.cpp
        #chapter9_Inheritance/TestCharArray.cpp
        #chapter7_ArraysStrings/MyStringTest.cpp
include/Fraction.h
include/VectorOp.h
include/String.h
include/Character.h)

add_executable(C__Tutorial ${SOURCE_FILES})