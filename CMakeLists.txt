cmake_minimum_required(VERSION 3.20)
project(TanksPlusPlus)

set(CMAKE_CXX_STANDARD 14)
set(SFML_STATIC_LIBARIES TRUE)
set(SFML_DIR C:/SFML/lib/cmake/SFML)

find_package(SFML COMPONENTS system window graphics audio network REQUIRED)

include_directories(c:/SFML/include)

include_directories(TanksPlusPlus/)

add_executable(TanksPlusPlus
        Game.cpp
        Game.h
        main.cpp
        Player.cpp
        Player.h
        Wall.cpp
        Wall.h
        MainMenu.cpp
        MainMenu.h)

target_link_libraries(TanksPlusPlus sfml-system sfml-window sfml-graphics sfml-audio)
