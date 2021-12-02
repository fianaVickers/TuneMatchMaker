cmake_minimum_required(VERSION 3.15)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(SongEditorFinder)
set(SFML_DIR "C:/Users/fiana/Downloads/SFML-2.5.1-windows-gcc-7.3.0-mingw-64-bit/SFML-2.5.1/lib/cmake/SFML")

find_package(SFML 2.5.1 COMPONENTS graphics audio REQUIRED)

add_executable(SongEditorFinder main.cpp TextureManager.cpp TextureManager.h)

target_link_libraries(SongEditorFinder sfml-graphics sfml-audio)