cmake_minimum_required(VERSION 3.5)
project(MyPhysicEngineInC++)

add_compile_options(-Wall -Wextra -Werror)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/geometry)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/demos)
