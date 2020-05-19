#include <window.hpp>
#include <scene.hpp>
#include <sprite.hpp>
#include <vec.hpp>

#include <iostream>

int main(int argc, char *arge[])
{

    bet::vec2 v1(10.0f, 10.0f);
    bet::vec2 v2(20.0f, 20.0f);
    bet::vec2 r = v1 + v2;

    std::cout << " v1 * v2: " << r.x << std::endl;

    // Sprite sprite("./Resources/demo.jpg", bet::vec2(200.0f, 200.0f), bet::vec2(100.0f, 100.0f));
    // Scene scene = Scene();
    // scene.AddChild(sprite);

    // Window window(500, 600, "Breakout");
    // window.RunScene(scene);

    return 1;
}