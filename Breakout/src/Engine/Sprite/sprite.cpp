#include "sprite.hpp"
#include "resourcemanager.hpp"

#include <iostream>

Sprite::Sprite(const std::string file_name, const bet::vec2<float> &position, const bet::vec2<float> &size)
    : file_name_(file_name), position_(position), size_(size), scale_(1.0f), rotate_(0.0f)
{
}

Sprite::Sprite() : file_name_(nullptr), scale_(1.0f), rotate_(0.0f)
{
    position_ = bet::vec2<float>(0.0f, 0.0f);
    size_ = bet::vec2<float>(0.0f, 0.0f);
}

Sprite::~Sprite() {}

void Sprite::LoadTexture(Shader &shader)
{
    shader.Use();
    Texture2D t = ResourceManager::CreateTexture2D(file_name_.c_str(), false, "Demo");
    shader.SetVector3f("SpriteColor", 1.0f, 0.0f, 0.0f);
    //  Texture2D texture =
}

Texture2D Sprite::GetTexture()
{
    return ResourceManager::GetTexture2D("Demo");
}