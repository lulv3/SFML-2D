#ifndef FIREBALL_H
#define FIREBALL_H

#include <SFML/Graphics.hpp>
#include "Sprite.h"
#include <string>

class Fireball {
public:
    Fireball(const sf::Vector2f& position, const sf::Vector2f& direction, float width, float height);
    void update();
    void draw(class Window& window);
    sf::FloatRect getBounds() const;
    sf::Sprite getSprite() {
        return sprite.getSprite();
    }

private:
    Sprite sprite;
    sf::Texture texture;
    sf::Vector2f direction;
};

#endif
