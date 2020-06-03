#ifndef WINDOW_H
#define WINDOW_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "spriterenderer.hpp"
#include "scene.hpp"
#include "event.hpp"

class Window
{
public:
    Window(int width, int height, const char *title);
    ~Window();

    void RunScene(Scene &scene);

    int GetWidth() const { return width_; }
    int GetHeight() const { return height_; }

    void AddEventHandler(Key key, EventState state, EventHandlerFun handler);

private:
    int width_;
    int height_;
    const char *title_;
    Scene scene_;

    void Init();
    void Render();
    void ProcessInput(GLFWwindow *window);
    void FramebufferSizeChanged(GLFWwindow *window, int width, int height);
    void Update();

    std::vector<EventHandler> eventHandlers_;
};

#endif
