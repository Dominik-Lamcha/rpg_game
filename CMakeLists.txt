cmake_minimum_required(VERSION 3.0)
project(RPG_GAME)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)

add_executable(RPG_GAME src/main.cpp)

target_link_libraries(RPG_GAME sfml-graphics sfml-audio)
