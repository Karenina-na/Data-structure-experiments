cmake_minimum_required(VERSION 3.25)

project(Data_structure_experiments)

# 编译器
set(CMAKE_CXX_COMPILER "g++")
set(CMAKE_C_COMPILER "gcc")

# 编译路径
set (EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

# 添加源文件
aux_source_directory (src SRC_LIST)

# 添加头文件目录
include_directories(include)

# 添加可执行文件
add_executable(Data_structure_experiments main.cpp ${SRC_LIST})