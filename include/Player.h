#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>
#include <string>
#include <imgui.h>
#include <imgui-SFML.h>
#include "Sprite.h"
#include "Input.h"

class Player {
public:
    Player();
    void move(const sf::Vector2f& direction);
    void draw(class Window& window);
    sf::FloatRect getBounds() const;
    sf::Sprite getSprite() const {
        return sprite.getSprite();
    }
    void renderImGui();
    void handleInput();

private:
    Sprite sprite;
    sf::Texture texture;

    float speed = 0.3f;
    float width;
    float height;
    bool collisionVisible;
};

#endif
