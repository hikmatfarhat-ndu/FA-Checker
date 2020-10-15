cmake_minimum_required(VERSION 3.10.0)
project (FA-Checker LANGUAGES CXX)
set(CMAKE_SUPPRESS_REGENERATION true)
set(CMAKE_CXX_STANDARD 17)
#SET(CMAKE_INCLUDE_PATH ${CMAKE_INCLUDE_PATH} "C:/Program Files/Boost/boost_1_74_0/boost_1_74_0")

find_package(Boost 1.72.0) 

add_executable(FA-Checker FA-Checker.cpp readFA.cpp readTests.cpp )
target_include_directories(FA-Checker PUBLIC "${PROJECT_SOURCE_DIR}")
include_directories(${Boost_INCLUDE_DIRS}) 
