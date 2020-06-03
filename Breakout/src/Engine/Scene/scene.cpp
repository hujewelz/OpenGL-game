#include "scene.hpp"
#include "texture.hpp"

#include <iostream>

// #include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

Scene::Scene()
{
}

Scene::~Scene()
{
    delete renderer_;
    for (auto child : children_)
    {
        delete child;
    }
}

void Scene::AddChild(Sprite *sprite)
{
    children_.push_back(sprite);
}

void Scene::Init()
{

    Shader shader = ResourceManager::CreateShader("./Resources/core.vs", "./Resources/core.fs", "Breakout");
    shader.Use();
    // set projection
    glm::mat4 projection = glm::ortho(0.0f, static_cast<GLfloat>(600), static_cast<GLfloat>(800), 0.0f, -1.0f, 1.0f);
    shader.SetInt("image", 0);
    shader.SetMatrix4("projection", projection);
    renderer_ = new SpriteRenderer(shader);

    for (Sprite *sprite : children_)
    {
        sprite->LoadTexture(shader);
    }
}

void Scene::Render()
{
    for (Sprite *sprite : children_)
    {
        renderer_->Render(*sprite);
    }
}