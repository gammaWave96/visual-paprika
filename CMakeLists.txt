cmake_minimum_required(VERSION 3.16.3)
project(VisualPaprika)
add_executable(${PROJECT_NAME} VisualPaprika/main.cpp)

add_subdirectory(3rdParty/glfw)

target_include_directories(
    ${PROJECT_NAME} 
    PUBLIC 3rdParty/glfw/include
    )

target_link_directories(
    ${PROJECT_NAME} 
    PRIVATE 3rdParty/glfw/src
    )

target_link_libraries(
    ${PROJECT_NAME}
    glfw
    )