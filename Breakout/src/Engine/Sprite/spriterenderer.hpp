#ifndef SPRITERENDER_H
#define SPRITERENDER_H

#include <GL/glew.h>

#include "shader.hpp"
#include "sprite.hpp"
#include "vec.hpp"

class SpriteRenderer
{
public:
    SpriteRenderer(Shader &shader);
    ~SpriteRenderer();
    void Render(Sprite &sprite);

private:
    Shader shader_;
    GLuint VAO_;
    void init();
};

#endif