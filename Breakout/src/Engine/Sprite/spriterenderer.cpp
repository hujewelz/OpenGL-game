#include "spriterenderer.hpp"
#include "resourcemanager.hpp"

#include <iostream>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

SpriteRenderer::SpriteRenderer(Shader &shader)
{
    this->shader_ = shader;
    this->init();
}

SpriteRenderer::~SpriteRenderer()
{
    glDeleteVertexArrays(1, &this->VAO_);
}

void SpriteRenderer::Render(Sprite &sprite)
{
    this->shader_.Use();
    glm::mat4 model = glm::mat4(1.0f);
    // model = glm::translate(model, glm::vec3(sprite.GetPosition().x, sprite.GetPosition().y, 0.0f));

    glActiveTexture(GL_TEXTURE0);
    sprite.GetTexture().Bind();
    glBindVertexArray(this->VAO_);
    glDrawArrays(GL_TRIANGLES, 0, 6);
    glBindVertexArray(0);
}

void SpriteRenderer::init()
{
    float vertices[] = {
        // pos      // tex
        0.0f, 1.0f, 0.0f, 1.0f,
        1.0f, 0.0f, 1.0f, 0.0f,
        0.0f, 0.0f, 0.0f, 0.0f,

        0.0f, 1.0f, 0.0f, 1.0f,
        1.0f, 1.0f, 1.0f, 1.0f,
        1.0f, 0.0f, 1.0f, 0.0f};

    GLuint VBO;
    glGenVertexArrays(1, &this->VAO_);
    glGenBuffers(1, &VBO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glBindVertexArray(this->VAO_);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 4, GL_FLOAT, false, 4 * sizeof(float), (void *)0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}