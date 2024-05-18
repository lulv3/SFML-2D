#include "Fireball.h"
#include "Window.h"

Fireball::Fireball(const sf::Vector2f& position, const sf::Vector2f& direction, float width, float height)
    : direction(direction), sprite() {
    sprite.loadTextureFromFile("Assets/Game/Star_Red.png");
    sprite.setPosition(position.x, position.y);
    sprite.setScale(width, height);
}

void Fireball::update() {
    sprite.move(direction.x, direction.y);
}

void Fireball::draw(Window& window) {
    window.draw(sprite.getSprite());
}

sf::FloatRect Fireball::getBounds() const {
    return sprite.getGlobalBounds();
}
