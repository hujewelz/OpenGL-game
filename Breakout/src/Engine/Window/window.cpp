#include "window.hpp"
#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "resourcemanager.hpp"
#include "texture.hpp"

// Create SpriteRender
SpriteRenderer *sprite_render_;

Window::Window(int width, int height, const char *title) : width_(width), height_(height), title_(title)
{
}

Window::~Window()
{
    delete sprite_render_;
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
    // glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    glewExperimental = GL_TRUE;
    if (glewInit() != GLEW_OK)
    {
        std::cout << "Init glew failed";
        return;
    }

    Shader shader = ResourceManager::CreateShader("Resources/core.vs", "Resources/core.fs", "Breakout");
    sprite_render_ = new SpriteRenderer(shader);
    Texture2D t = ResourceManager::CreateTexture2D("./Resources/demo.jpg", false, "Demo");

    // render loop
    while (!glfwWindowShouldClose(window))
    {
        glfwPollEvents();
        // ProcessInput(window);

        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        this->Render();
        glfwSwapBuffers(window);
    }

    // glfw: terminate, clearing all previously allocated GLFW resources.
    glfwTerminate();
}
void Window::Update() {}

void Window::Render()
{
    // TODO: Load text form sprite
    Texture2D texture = ResourceManager::GetTexture2D("Demo");
    sprite_render_->Render(texure);
}