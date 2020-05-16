#ifndef WINDOW_H
#define WINDOW_H

#include <GL/glew.h>
#include "spriterenderer.hpp"

class Window
{
public:
    Window(int width, int height, const char *title);
    ~Window();

    void Init();
    void Update();
    void Render();
    void ProcessInput();

    int GetWidth() { return width_; }
    int GetHeight() { return height_; }

private:
    int width_;
    int height_;
    const char *title_;
    static SpriteRenderer *sprite_renderer_;
};

#endif
