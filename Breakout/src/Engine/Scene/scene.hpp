#ifndef SCENE_H
#define SCENE_H

#include "resourcemanager.hpp"
#include "spriterenderer.hpp"

class Scene
{
public:
    static Scene *Create();
    Scene();
    ~Scene();

    void Init();
    void Render();

private:
    SpriteRenderer *render;
};

#endif