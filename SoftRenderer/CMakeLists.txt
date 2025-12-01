## 最小CMake版本要求
cmake_minimum_required(VERSION 3.15)
## 子项目模块名
set(SUB_MODULE_NAME SoftRenderer)
## 设置源文件目录
set(ALL_SOURCE_FILES
Core/Renderer.cpp
Core/Renderer.h
Math/Vec.cpp
Math/Vec.h
)
## 编译为静态库
add_library(${SUB_MODULE_NAME} STATIC ${ALL_SOURCE_FILES})
## 设置Include目录
target_include_directories(${SUB_MODULE_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/${SUB_MODULE_NAME})