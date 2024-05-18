#include "Fireball.h"
#include "Window.h"

Fireball::Fireball(const std::string& textureFile, const sf::Vector2f& position, const sf::Vector2f& direction, float width, float height)
    : direction(direction) {
    sf::Texture texture;
    texture.loadFromFile(textureFile);
    sprite.setTexture(texture);
    sprite.setPosition(position);
    sprite.setScale(width / sprite.getLocalBounds().width, height / sprite.getLocalBounds().height);
}

void Fireball::update() {
    sprite.move(direction);
}

void Fireball::draw(Window& window) {
    window.draw(sprite);
}

sf::FloatRect Fireball::getBounds() const {
    return sprite.getGlobalBounds();
}
