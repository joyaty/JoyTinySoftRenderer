cmake_minimum_required(VERSION 3.5)

project(JoyTinySoftRenderer)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_definitions(-DUNICODE -D_UNICODE)

set(ALL_CPP_FILE
src/Main.cpp)

add_executable(${PROJECT_NAME} ${ALL_CPP_FILE})