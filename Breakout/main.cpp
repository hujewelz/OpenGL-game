#include <window.hpp>
#include <scene.hpp>

#include <iostream>

int main(int argc, char *arge[])
{
    Scene s = Scene();
    Window window(500, 600, "Breakout");
    window.RunScene(s);

    return 1;
}