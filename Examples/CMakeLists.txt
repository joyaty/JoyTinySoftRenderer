# cmake 最低版本号要求
cmake_minimum_required(VERSION 3.15)
## 设置示例程序子模块名
set(EXAMPLE_MODULE_NAME Examples)
## 设置示例程序源文件目录
set(ALL_SRC_FILES
Main.cpp
)
## 编译为可执行文件
add_executable(${EXAMPLE_MODULE_NAME} ${ALL_SRC_FILES})
## 设置Include目录
target_include_directories(${EXAMPLE_MODULE_NAME} PRIVATE ${PROJECT_SOURCE_DIR}/Examples)
## 链接软光栅模块
target_link_libraries(${EXAMPLE_MODULE_NAME} PRIVATE SoftRenderer)