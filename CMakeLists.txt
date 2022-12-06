cmake_minimum_required(VERSION 3.23)
project(Lydian)

set(CMAKE_CXX_STANDARD 17)


find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)
add_executable(Lydian main.cpp PositionFunctions.cpp link.h AssetHandler.cpp ButtonHandler.cpp)

target_link_libraries(Lydian sfml-graphics sfml-audio)
