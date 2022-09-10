# Learning Cpp
Just a place for me to write some cpp sample codes while learning cpp.

## To build with CMake
```
mkdir build
cd build
cmake ..
cmake --build .
```

## To run the executables generated using CMake
- Go to the build directory and run the executables there
- Take note that some executables such as the raceConditionExample need you to create some files for proper demonstration

## To generate executable using g++
For normal program:
```
g++ program-name.cpp -o output-name
```
For multi-threaded program:
```
g++ -pthread program-name.cpp -o output-name
```