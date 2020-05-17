#include "scene.hpp"
#include "texture.hpp"

#include <iostream>

Scene *Scene::Create()
{
    return new Scene();
}

Scene::Scene()
{
}

Scene::~Scene()
{
    delete render;
}

void Scene::AddChild(const Sprite &sprite)
{
    this->children.push_back(sprite);
}

void Scene::Init()
{

    Shader shader = ResourceManager::CreateShader("./Resources/core.vs", "./Resources/core.fs", "Breakout");
    shader.Use();
    render = new SpriteRenderer(shader);

    // TODO: create all texture form sprites
    for (Sprite &sprite : children)
    {
        sprite.LoadTexture(shader);
    }
    shader.SetInt("image", 0);
}

void Scene::Render()
{
    // TODO: Load text form sprites
    for (Sprite &sprite : children)
    {
        render->Render(sprite);
    }
}