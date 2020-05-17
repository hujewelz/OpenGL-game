#include <window.hpp>
#include <scene.hpp>
#include <sprite.hpp>
#include <vec.hpp>

#include <iostream>

int main(int argc, char *arge[])
{

    Sprite sprite("./Resources/demo.jpg", bet::vec2<float>(200.0f, 200.0f), bet::vec2<float>(100.0f, 100.0f));
    Scene scene = Scene();
    scene.AddChild(sprite);

    Window window(500, 600, "Breakout");
    window.RunScene(scene);

    return 1;
}