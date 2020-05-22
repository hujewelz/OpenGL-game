#include "window.hpp"

#include <iostream>

#include "resourcemanager.hpp"
#include "texture.hpp"

Window::Window(int width, int height, const char *title)
    : width_(width), height_(height), title_(title)
{
}

Window::~Window()
{
}

void Window::RunScene(Scene &scene)
{
    scene_ = scene;
    Init();
}

void Window::Init()
{
    // glfw: initialize and configure
    // ------------------------------
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    // glfw window creation
    // --------------------
    GLFWwindow *window = glfwCreateWindow(width_, height_, title_, NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return;
    }
    glfwMakeContextCurrent(window);

    // typedef void *(*Callback)(void *, GLFWwindow *, int, int);
    // Callback callback = (Callback) & (Window::FramebufferSizeChanged);
    // glfwSetFramebufferSizeCallback(window, callback);
    glewExperimental = GL_TRUE;
    if (glewInit() != GLEW_OK)
    {
        std::cout << "Init glew failed";
        return;
    }

    // TODO: Add Scene
    scene_.Init();

    // render loop
    while (!glfwWindowShouldClose(window))
    {
        ProcessInput(window);

        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        Render();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    ResourceManager::Clear();
    // glfw: terminate, clearing all previously allocated GLFW resources.
    glfwTerminate();
}
void Window::Update()
{
}

void Window::ProcessInput(GLFWwindow *window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

void Window::FramebufferSizeChanged(GLFWwindow *window, int width, int height)
{
    width_ = width;
    height_ = height;
    glViewport(0, 0, width, height);
}

void Window::Render()
{
    scene_.Render();
}