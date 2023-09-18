cmake_minimum_required(VERSION 3.16.3)
project(VisualPaprika)
add_executable(${PROJECT_NAME} VisualPaprika/main.cpp)

add_subdirectory(3rdParty/glfw)

target_sources(
    ${PROJECT_NAME}
    PUBLIC
    VisualPaprika/utils.cpp
    VisualPaprika/utils.hpp
)

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

if(MSVC)
    target_include_directories( 
        ${PROJECT_NAME} 
	    PUBLIC F:/ASSETS/VULKAN_SDK/Include
    )
    target_link_directories(
        ${PROJECT_NAME}
        PRIVATE F:/ASSETS/VULKAN_SDK/Lib
    )
    target_link_libraries(
    ${PROJECT_NAME}
    Vulkan-1.lib
    )
else()
endif()


