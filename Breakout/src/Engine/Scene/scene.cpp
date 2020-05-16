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

void Scene::Init()
{
    Shader shader = ResourceManager::CreateShader("./Resources/core.vs", "./Resources/core.fs", "Breakout");
    shader.Use();
    render = new SpriteRenderer(shader);

    // crate all texture form sprites
    ResourceManager::CreateTexture2D("./Resources/demo.jpg", false, "Demo");

    shader.SetVector3f("SpriteColor", 1.0f, 0.0f, 0.0f);
}

void Scene::Render()
{
    // TODO: Load text form sprites
    Texture2D texture = ResourceManager::GetTexture2D("Demo");
    render->Render(texture);
}