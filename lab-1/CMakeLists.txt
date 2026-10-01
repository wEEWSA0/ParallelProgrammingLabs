cmake_minimum_required(VERSION 3.20)
project(lab-1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(Threads REQUIRED)

add_executable(lab-1 main.cpp)
target_link_libraries(lab-1 PRIVATE Threads::Threads)