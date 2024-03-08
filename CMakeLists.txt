cmake_minimum_required(VERSION 3.27)
project(adm345)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(admStructures)

add_executable(adm345 main.cpp)
target_link_libraries(adm345 PUBLIC adm)
