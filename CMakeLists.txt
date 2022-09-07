cmake_minimum_required(VERSION 3.23)
project(2DPhysix)

set(CMAKE_CXX_STANDARD 14)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

add_subdirectory(Dependencies/glfw
        src/Vendor/imgui
        )



add_executable(2DPhysix
        main.cpp
        glad.c
        src/Classes/AbstractImGui.cpp
        src/Classes/IndexBufferClass.cpp
        src/Classes/Renderer.cpp
        src/Classes/ShaderClass.cpp
        src/Classes/Starter.cpp
        src/Classes/VertexArrayClass.cpp
        src/Classes/VertexBufferClass.cpp
        src/Classes/VertexBufferLayoutClass.cpp
        src/Classes/AbstractImGui.h
        src/Classes/IndexBufferClass.h
        src/Classes/Renderer.h
        src/Classes/ShaderClass.h
        src/Classes/Starter.h
        src/Classes/VertexArrayClass.h
        src/Classes/VertexBufferClass.h
        src/Classes/VertexBufferLayoutClass.h
        Dependencies/imgui/imgui.cpp
        Dependencies/imgui/imgui_demo.cpp
        Dependencies/imgui/imgui_draw.cpp
        Dependencies/imgui/imgui_tables.cpp
        Dependencies/imgui/imgui_widgets.cpp
        Dependencies/imgui/backends/imgui_impl_glfw.cpp
        Dependencies/imgui/backends/imgui_impl_opengl3.cpp
        src/Test/ArraySorting.h
        src/Test/ArraySorting.cpp
        src/Classes/Events/Event.h
        )


target_include_directories(2DPhysix PRIVATE src/Classes
        Dependencies/glfw
        Dependencies/include
        src/Vendor
        src/Classes
        Dependencies
        Dependencies/imgui
        Dependencies/spdlog/include
        )

target_link_libraries(${PROJECT_NAME} glfw)


