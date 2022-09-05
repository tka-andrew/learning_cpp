cmake_minimum_required(VERSION 3.0)

project(LearningCpp VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# needed for multi-threaded program
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -pthread")

# executables
add_executable(friendClassExample src/friend_class_example.cpp)
add_executable(multithreadedExample src/multithreaded_example.cpp)

