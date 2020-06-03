#ifndef SCENE_H
#define SCENE_H

#include "resourcemanager.hpp"
#include "spriterenderer.hpp"
#include "sprite.hpp"

#include <vector>

class Scene
{
public:
    Scene();
    ~Scene();

    // load shader and textures
    void Init();

    // render all sprites
    void Render();

    void AddChild(Sprite *sprite);

private:
    SpriteRenderer *renderer_;
    std::vector<Sprite *> children_;
};

#endif