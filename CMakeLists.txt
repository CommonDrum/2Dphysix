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
        src/Renderer/AbstractImGui.cpp
        src/Renderer/IndexBufferClass.cpp
        src/Renderer/Renderer.cpp
        src/Renderer/ShaderClass.cpp
        src/Renderer/Starter.cpp
        src/Renderer/VertexArrayClass.cpp
        src/Renderer/VertexBufferClass.cpp
        src/Renderer/VertexBufferLayoutClass.cpp
        src/Renderer/AbstractImGui.h
        src/Renderer/IndexBufferClass.h
        src/Renderer/Renderer.h
        src/Renderer/ShaderClass.h
        src/Renderer/Starter.h
        src/Renderer/VertexArrayClass.h
        src/Renderer/VertexBufferClass.h
        src/Renderer/VertexBufferLayoutClass.h
        Dependencies/imgui/imgui.cpp
        Dependencies/imgui/imgui_demo.cpp
        Dependencies/imgui/imgui_draw.cpp
        Dependencies/imgui/imgui_tables.cpp
        Dependencies/imgui/imgui_widgets.cpp
        Dependencies/imgui/backends/imgui_impl_glfw.cpp
        Dependencies/imgui/backends/imgui_impl_opengl3.cpp
        src/Test/ArraySorting.h
        src/Test/ArraySorting.cpp
        src/Events/Event.h
        src/Events/ApplicationEvent.h src/Events/KeyEvent.h src/Events/MouseEvent.h src/Core/Core.h)


target_include_directories(2DPhysix PRIVATE src/Renderer
        Dependencies/glfw
        Dependencies/include
        src/Vendor
        src/Renderer
        Dependencies
        Dependencies/imgui
        Dependencies/spdlog/include
        )

target_link_libraries(${PROJECT_NAME} glfw)


