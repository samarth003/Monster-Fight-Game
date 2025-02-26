cmake_minimum_required(VERSION 3.10)
project(MonstersGaming) #Project name

set(CMAKE_CXX_STANDARD 17) #use c++17

#Add SFML 
set(SFML_DIR "C:/Softwares/SFML-3.0.0/lib/cmake/SFML")
find_package(SFML 3 COMPONENTS Graphics Audio System Window)

#Add header files directory
include_directories(
    ${CMAKE_SOURCE_DIR}/Header
    C:/Softwares/SFML-3.0.0/include
    )

#List all source files here
add_executable(MonsterBattle
    Source/LogR.cpp
    Source/Monsters.cpp
    Source/Dragons.cpp
    Source/Spiders.cpp
    Source/MonsterFightGame.cpp
    Source/RenderingGame.cpp
)

# add_executable(RenderTest
#     Source/RenderingGame.cpp
#     )

# Link SFML libraries
# target_link_libraries(RenderTest sfml-graphics sfml-audio sfml-system sfml-window)
target_link_libraries(MonsterBattle PRIVATE SFML::Graphics SFML::Audio)

enable_testing()

#Fetch content module to download GoogleTest
include(FetchContent)
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG        v1.16.0
)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

#Fetch GoogleTest and make it available for use
FetchContent_MakeAvailable(googletest)

#add test files here
add_executable(
    test_monsters
    tests/test_dragon.cpp
    tests/test_spider.cpp
    tests/test_monsterfightgame.cpp
    Source/Dragons.cpp
    Source/Spiders.cpp
    Source/Monsters.cpp
    Source/LogR.cpp
    Source/MonsterFightGame.cpp
    # Source/RenderingGame.cpp
)
#Link against GoogleTest
target_link_libraries(test_monsters GTest::gmock GTest::gtest_main)
target_compile_definitions(test_monsters PRIVATE UNIT_TEST)

# Register tests
include(GoogleTest)
gtest_discover_tests(test_monsters)



