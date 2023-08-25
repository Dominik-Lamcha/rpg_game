cmake_minimum_required(VERSION 3.0)
project(RPG_GAME)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)
include_directories(${CMAKE_SOURCE_DIR}/src/include)

add_library(MyLibrary src/simple_lib.cpp)


add_executable(RPG_GAME src/main.cpp)

target_link_libraries(RPG_GAME sfml-graphics sfml-audio)
