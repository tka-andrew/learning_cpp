# Learning Cpp
Just a place for me to write some cpp sample codes while learning cpp.

## To build with CMake
```
mkdir build
cd build
cmake ..
cmake --build .
```

## To generate executable using g++
For normal program:
```
g++ program-name.cpp -o output-name
```
For multi-threaded program:
```
g++ -pthread program-name.cpp -o output-name
```