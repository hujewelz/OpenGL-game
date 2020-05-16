#ifndef SPRITERENDER_H
#define SPRITERENDER_H

#include <GL/glew.h>

#include "shader.hpp"
#include "texture.hpp"

class SpriteRenderer
{
public:
    SpriteRenderer(Shader &shader);
    ~SpriteRenderer();
    void Render(Texture2D &texture /*, vec*/);

private:
    Shader shader_;
    GLuint VAO_;
    void init();
};

#endif