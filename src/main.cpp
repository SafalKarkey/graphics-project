#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include<iostream>

const int SCR_WIDTH = 1280;
const int SCR_HEIGHT = 720;

void framebuffer_size_callback(GLFWwindow *window, int width, int height)
{
    glViewport(0, 0, SCR_WIDTH, SCR_HEIGHT);
}

void process_input(GLFWwindow *window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
    {
        std::cout << "Pressed Esc, exiting..." << std::endl;
        glfwSetWindowShouldClose(window, true);
    }
}

int main()
{
    // initialize GLFW
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    // glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    GLFWwindow *window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "Opengl project", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    // intialize GLAD to load function pointers to openGL functions
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    while (!glfwWindowShouldClose(window))
    {
        process_input(window);
        // rendering
        glClearColor(0.4f, 0.8f, 0.45f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // DRAWING PART

        // check and call events and swap buffers
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();

    return 0;
}