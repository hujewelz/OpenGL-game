#include "scene.hpp"
#include "texture.hpp"

#include <iostream>

Scene::Scene()
{
}

Scene::~Scene()
{
    delete renderer_;
}

void Scene::AddChild(const Sprite &sprite)
{
    children_.push_back(sprite);
}

void Scene::Init()
{

    Shader shader = ResourceManager::CreateShader("./Resources/core.vs", "./Resources/core.fs", "Breakout");
    shader.Use();
    renderer_ = new SpriteRenderer(shader);

    // TODO: create all texture form sprites
    for (Sprite &sprite : children_)
    {
        sprite.LoadTexture(shader);
    }
    shader.SetInt("image", 0);
}

void Scene::Render()
{
    // TODO: Load text form sprites
    for (Sprite &sprite : children_)
    {
        renderer_->Render(sprite);
    }
}