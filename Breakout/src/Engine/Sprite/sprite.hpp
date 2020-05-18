#ifndef SPRITE_H
#define SPRITE_H

#include "vec.hpp"
#include "texture.hpp"
#include "shader.hpp"

#include <string>

class Sprite
{
public:
    Sprite();
    Sprite(const std::string file_name, const bet::vec2<float> &position, const bet::vec2<float> &size);
    ~Sprite();

    Texture2D GetTexture() const;

    void LoadTexture(Shader &shader);

    const std::string &GetFileName() const { return this->file_name_; };
    const bet::vec2<float> &GetPosition() const { return this->position_; }
    const bet::vec2<float> &GetSize() const { return this->size_; }
    float GetScale() const { return this->scale_; }
    float GetRatate() const { return this->rotate_; }

private:
    std::string file_name_;
    bet::vec2<float> position_;
    bet::vec2<float> size_;
    float scale_;
    float rotate_;
};

#endif