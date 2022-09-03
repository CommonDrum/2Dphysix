cmake_minimum_required(VERSION 3.23)
project(2DPhysix)

set(CMAKE_CXX_STANDARD 14)

add_executable(2DPhysix main.cpp)
add_subdirectory(src/Classes)
target_link_directories(2DPhysix PUBLIC src/Classes)


set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
target_include_directories(2DPhysix PRIVATE Dependencies/include)

target_include_directories(2DPhysix PRIVATE src/Vendor)
target_include_directories(2DPhysix PRIVATE src/Classes)

