cmake_minimum_required(VERSION 3.16.3)
project(VisualPaprika)
add_executable(${PROJECT_NAME} VisualPaprika/main.cpp)

add_subdirectory(3rdParty/glfw)