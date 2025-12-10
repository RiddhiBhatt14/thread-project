cmake_minimum_required(VERSION 3.10)
project(app)
set(CMAKE_CXX_STANDARD 20)

include_directories(include)


add_executable(app
    src/main.cpp
    src/threadManager.cpp
)
