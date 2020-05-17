#ifndef SPRITE_H
#define SPRITE_H

#include "vec.hpp"
#include "texture.hpp"
#include "shader.hpp"

#include <string>

class Sprite
{
public:
    Sprite(const std::string file_name, const bet::vec2<float> &position, const bet::vec2<float> &size);
    Sprite();
    ~Sprite();

    Texture2D GetTexture();

    void LoadTexture(Shader &shader);

    const std::string GetFileName() { return this->file_name_; };
    const bet::vec2<float> GetPosition() { return this->position_; }
    const bet::vec2<float> GetSize() { return this->size_; }
    const float GetScale() { return this->scale_; }
    const float GetRatate() { return this->rotate_; }

private:
    std::string file_name_;
    bet::vec2<float> position_;
    bet::vec2<float> size_;
    float scale_;
    float rotate_;
};

#endif