cmake_minimum_required(VERSION 3.20)
project(Variant12StudentB LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_subdirectory(StaticLibrary)
add_subdirectory(DynamicLibrary)
add_subdirectory(ImplicitClient)
add_subdirectory(ExplicitClient)
