cmake_minimum_required(VERSION 3.23)
project(2DPhysix)

set(CMAKE_CXX_STANDARD 14)
file(GLOB SOURCES "src/Classes/*.cpp" )
file(GLOB SOURCES "src/*.cpp" )
add_executable(2DPhysix main.cpp glad.c
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
        Dependencies/include/GLFW/glfw3.h

        )

target_link_directories(2DPhysix PUBLIC src/Classes)
target_include_directories(2DPhysix PRIVATE src/Classes)

target_include_directories(2DPhysix PRIVATE Dependencies/include)

target_include_directories(2DPhysix PRIVATE src/Vendor)
target_include_directories(2DPhysix PRIVATE src/Classes)

