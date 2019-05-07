cmake_minimum_required(VERSION 3.12)
project(my_game)
set(EXECUTABLE_NAME "my_game")
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_MODULE_PATH  ${CMAKE_MODULE_PATH} "/usr/share/SFML/cmake/Modules")
add_executable(${EXECUTABLE_NAME} main.cpp MAIN_HEADER.h textures.cpp subjects.cpp subjects.h)
find_package(SFML 2.4.1 COMPONENTS network graphics audio window system REQUIRED)
target_link_libraries(my_game sfml-graphics sfml-audio sfml-window sfml-system)



