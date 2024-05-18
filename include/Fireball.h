#ifndef FIREBALL_H
#define FIREBALL_H

#include <SFML/Graphics.hpp>
#include <string>

class Fireball {
public:
    Fireball(const std::string& textureFile, const sf::Vector2f& position, const sf::Vector2f& direction, float width, float height);
    void update();
    void draw(class Window& window);
    sf::FloatRect getBounds() const;
    sf::Sprite getSprite() {
        return sprite;
    }

private:
    sf::Sprite sprite;
    sf::Vector2f direction;
};

#endif
