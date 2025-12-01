## CMake 最低版本号要求
cmake_minimum_required(VERSION 3.15)
## 设置项目名称
project(JoyTinySoftRenderer)
## 可选开启测试模块
option(ENABLE_TESTING "Enable Testing Module" ON)
## 设置C++标准
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(MSVC)
    # Windows下使用Unicode编码
    add_definitions(-DUNICODE -D_UNICODE)
endif()

if(ENABLE_TESTING)
    ## 启动测试模块
    enable_testing()
endif()

## 软光栅模块
add_subdirectory(${PROJECT_SOURCE_DIR}/SoftRenderer)
## 示例程序
add_subdirectory(${PROJECT_SOURCE_DIR}/Examples)
if(ENABLE_TESTING)
    ## 测试用例
    add_subdirectory(${PROJECT_SOURCE_DIR}/Tests)
endif()