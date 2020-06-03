#include "sprite.hpp"
#include "resourcemanager.hpp"

#include <iostream>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

Sprite::Sprite(
    const std::string file_name,
    const bet::vec2 &position,
    const bet::vec2 &size)
    : file_name_(file_name),
      position_(position),
      size_(size),
      scale_(1.0f),
      rotate_(0.0f),
      color_(1.0f, 1.0f, 1.0f) {}

Sprite::Sprite()
    : file_name_(nullptr),
      position_(0.0f, 0.0f),
      size_(0.0f, 0.0f),
      scale_(1.0f),
      rotate_(0.0f),
      color_(1.0f, 1.0f, 1.0f) {}

Sprite::~Sprite() {}

Sprite *Sprite::Create(const std::string file_name, const bet::Rect rect)
{
    return new Sprite(file_name, rect.origin, rect.size);
}

void Sprite::LoadTexture(Shader &shader)
{
    ResourceManager::CreateTexture2D(file_name_, false);
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

void Sprite::SetColor(const bet::vec3 &color)
{
    color_ = color;
}