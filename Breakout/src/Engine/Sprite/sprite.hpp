#ifndef SPRITE_H
#define SPRITE_H

#include "vec.hpp"
#include "texture.hpp"
#include "shader.hpp"

#include <string>

class Sprite
{
public:
    ~Sprite();

    static Sprite *Create(const std::string file_name, const bet::vec2 &position, const bet::vec2 &size);

    Texture2D GetTexture() const;

    void LoadTexture(Shader &shader);

    const std::string &GetFileName() const { return file_name_; }
    const bet::vec2 &GetPosition() const { return position_; }
    const bet::vec2 &GetSize() const { return size_; }
    float GetScale() const { return scale_; }
    float GetRotate() const { return rotate_; }
    const bet::vec3 &GetColor() const { return color_; }

    void SetPosition(const bet::vec2 &position);
    void SetSize(const bet::vec2 &size);
    void SetScale(const float scale);
    void SetRotate(const float rotate);
    void SetColor(const bet::vec3 &color);

private:
    Sprite();
    Sprite(const std::string file_name, const bet::vec2 &position, const bet::vec2 &size);
    std::string file_name_;
    bet::vec2 position_;
    bet::vec2 size_;
    bet::vec3 color_;
    float scale_;
    float rotate_;
};

#endif