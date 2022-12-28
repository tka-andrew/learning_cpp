cmake_minimum_required(VERSION 3.0)

project(LearningCpp VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# needed for multi-threaded program
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -pthread")

add_subdirectory(src/DesignPatterns)

# executables
add_executable(friendClassExample src/friend_class_example.cpp)
add_executable(multithreadedExample src/multithreaded_example.cpp)
add_executable(reserveVsResize src/reserve_vs_resize.cpp)
add_executable(raceConditionExample src/race_condition_example.cpp)
add_executable(mutexLockUnlockExample src/mutex_lock_unlock_example.cpp)
add_executable(interactiveSignalHandleExample src/interactive_signal_handle_example.cpp)
