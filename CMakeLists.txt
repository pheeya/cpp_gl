cmake_minimum_required(VERSION 3.26.0)
project(cpp_gl_template)
add_executable(cpp_gl src/main.cpp)

add_subdirectory(thirdparty/glfw/)
add_subdirectory(thirdparty/glad/)
add_subdirectory(thirdparty/spdlog/) 
add_subdirectory(thirdparty/imgui/) 
add_subdirectory(thirdparty/glm/)
 
target_link_libraries(Imgui PRIVATE glfw)
target_link_libraries(cpp_gl glfw glad Imgui glm spdlog)           

target_include_directories(cpp_gl PUBLIC thirdparty/stb)