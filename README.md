# Data-structure-experiments

## NWPU data structure experiment

## Environment

- Windows 10
- MinGW-w64
- CMake 3.25.3
- GCC 12.2.0
- G++ 12.2.0
- GDB 12.1
- CLion 2023.1

## Change Function

if you want to change the function, you can change the `main.cpp` file.

## Notice
The project directory should not contain chinese characters.

## run
compile

```shell
cmake -DCMAKE_BUILD_TYPE=Debug -G "CodeBlocks - MinGW Makefiles" -S . -B ./cmake-build-debug-mingw
```

build

```shell
cmake --build ./cmake-build-debug-mingw --target Data_structure_experiments -- -j 14
```

run

```shell
./bin/Data_structure_experiments.exe
```