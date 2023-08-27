cmake_minimum_required(VERSION 3.26.0)
project(cpp_gl_template)
add_executable(cpp_gl src/main.cpp)

add_subdirectory(thirdparty/glfw/)
add_subdirectory(thirdparty/glad/)
add_subdirectory(thirdparty/spdlog/) 
add_subdirectory(thirdparty/imgui/) 

target_link_libraries(Imgui PRIVATE glfw)
target_link_libraries(cpp_gl glfw glad Imgui spdlog)           