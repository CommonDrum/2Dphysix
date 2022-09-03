cmake_minimum_required(VERSION 3.23)
project(2DPhysix)

set(CMAKE_CXX_STANDARD 14)

add_executable(2DPhysix main.cpp)
add_subdirectory(Dependecies/include)


find_package(glfw3 3.3 REQUIRED)
target_link_libraries(2DPhysix glfw)
find_package(OpenGL REQUIRED)
target_link_libraries(2DPhysix OpenGL::GL)

