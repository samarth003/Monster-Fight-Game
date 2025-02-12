cmake_minimum_required(VERSION 3.10)
project(MonstersGaming) #Project name

set(CMAKE_CXX_STANDARD 17) #use c++17 

#Add header files directory
include_directories(${CMAKE_SOURCE_DIR}/Header)

#List all source files here
add_executable(MonsterBattle
    Source/LogR.cpp
    Source/Monsters.cpp
    Source/Dragons.cpp
    Source/MonsterFightGame.cpp
)

