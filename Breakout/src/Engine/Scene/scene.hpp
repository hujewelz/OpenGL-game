#ifndef SCENE_H
#define SCENE_H

#include "resourcemanager.hpp"
#include "spriterenderer.hpp"
#include "sprite.hpp"

#include <vector>

class Scene
{
public:
    static Scene *Create();
    Scene();
    ~Scene();

    // load shader and textures
    void Init();

    // render all sprites
    void Render();

    void AddChild(const Sprite &sprite);

private:
    SpriteRenderer *render;
    std::vector<Sprite> children;
};

#endif