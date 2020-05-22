#include "sprite.hpp"
#include "resourcemanager.hpp"

#include <iostream>

Sprite::Sprite(
    const std::string file_name,
    const bet::vec2 &position,
    const bet::vec2 &size)
    : file_name_(file_name),
      position_(position),
      size_(size),
      scale_(1.0f),
      rotate_(0.0f) {}

Sprite::Sprite()
    : file_name_(nullptr),
      position_(0.0f, 0.0f),
      size_(0.0f, 0.0f),
      scale_(1.0f),
      rotate_(0.0f) {}

Sprite::~Sprite() {}

void Sprite::LoadTexture(Shader &shader)
{
    ResourceManager::CreateTexture2D(file_name_, false);
    shader.SetVector3f("spriteColor", 1.0f, 0.0f, 0.0f);
}

Texture2D Sprite::GetTexture() const
{
    return ResourceManager::GetTexture2D(file_name_);
}

void Sprite::SetPosition(const bet::vec2 &position)
{
    position_ = position;
}

void Sprite::SetSize(const bet::vec2 &size)
{
    size_ = size;
}

void Sprite::SetScale(const float scale)
{
    scale_ = scale;
}

void Sprite::SetRotate(const float rotate)
{
    rotate_ = rotate;
}