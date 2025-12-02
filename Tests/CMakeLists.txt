## cmake 最低版本号要求
cmake_minimum_required(VERSION 3.15)
## 设置测试子模块名
set(TEST_MODULE_NAME Tests)
## 从GitHub引入GoogleTest
include(FetchContent)
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG v1.17.0
)
## 禁用安装gtest和gmock
set(BUILD_GMOCK OFF CACHE BOOL "" FORCE)
set(INSTALL_GTEST OFF CACHE BOOL "" FORCE)
## 启用GoogleTest
FetchContent_MakeAvailable(googletest)
include(GoogleTest)
## 设置测试源文件目录
set(ALL_SRC_FILES
MathTest/MathTest.cpp
)
## 编译为可执行文件
add_executable(${TEST_MODULE_NAME} ${ALL_SRC_FILES})
## 设置Include目录
target_include_directories(${TEST_MODULE_NAME} PRIVATE ${PROJECT_SOURCE_DIR}/Tests)
## 链接软光栅模块和GoogleTest库
target_link_libraries(${TEST_MODULE_NAME} PRIVATE SoftRenderer gtest_main)
## 自动发现测试用例
gtest_discover_tests(${TEST_MODULE_NAME} WORKING_DIRECTIORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTIES TIMEOUT 60)
## 设置测试可执行文件输出目录
set_target_properties(${TEST_MODULE_NAME} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/Tests
)