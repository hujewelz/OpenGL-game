#include <window.hpp>
#include <scene.hpp>
#include <sprite.hpp>
#include <vec.hpp>

#include <iostream>

int main(int argc, char *arge[])
{
    Sprite sprite("./Resources/demo.jpg", bet::vec2(200.0f, 200.0f), bet::vec2(40.0f, 40.0f));

    Sprite sprite2("./Resources/demo.jpg", bet::vec2(400.0f, 200.0f), bet::vec2(100.0f, 100.0f));
    Scene scene;
    scene.AddChild(sprite);
    scene.AddChild(sprite2);

    Window window(500, 600, "Breakout");
    window.RunScene(scene);

    return 1;
}