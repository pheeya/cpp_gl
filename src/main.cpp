#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <spdlog/spdlog.h>
#include <iostream>

const GLuint WIDTH = 800, HEIGHT = 600;

void key_callback(GLFWwindow *window, int key, int scancode, int action, int mode)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);
}

int main(void)
{
    glfwInit();

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow *window = glfwCreateWindow(WIDTH, HEIGHT, "C++ OpenGL Glad GLFW", NULL, NULL);
    glfwMakeContextCurrent(window);

    glfwSetKeyCallback(window, key_callback);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        spdlog::critical("failed to initialize gl context");
        return -1;
    }

    spdlog::info("Created window");
    while (!glfwWindowShouldClose(window))
    {
        glfwPollEvents();

        glClearColor(0.4f, 0.7f, 0.4f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(window);
    }

    glfwTerminate();

    return 0;
}