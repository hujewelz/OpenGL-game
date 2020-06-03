#include <window.hpp>
#include <scene.hpp>
#include <sprite.hpp>
#include <vec.hpp>

#include <iostream>

int main(int argc, char *arge[])
{
    Sprite *sprite = Sprite::Create("./Resources/demo.jpg", bet::Rect(200.0f, 200.0f, 40.0f, 40.0f));

    Sprite *sprite2 = Sprite::Create("./Resources/demo.jpg", bet::Rect(400.0f, 200.0f, 100.0f, 100.0f));
    Scene scene;
    scene.AddChild(sprite);
    scene.AddChild(sprite2);

    Window window(500, 600, "Breakout");

    window.AddEventHandler(KEY_A, EVENT_STATE_PRESS, [sprite](Event event) {
        bet::vec2 p = sprite->GetPosition();
        sprite->SetPosition(p + bet::vec2(1.0f, 1.0f));
    });
    window.RunScene(scene);

    return 1;
}