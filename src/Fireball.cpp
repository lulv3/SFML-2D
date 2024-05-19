#include "Fireball.h"

Fireball::Fireball(float startX, float startY, bool moveRight, float speed)
    : moveRight(moveRight), speed(speed) {
    sprite.loadTextureFromFile("Assets/Game/Star_Red.png"); // Pfad zur Fireball-Textur
    sprite.setPosition(startX, startY);
    sprite.setScale(5, 5);
    collision.update(sprite.getSprite());
}

void Fireball::update(float deltaTime) {
    float offsetX = moveRight ? speed * deltaTime : -speed * deltaTime;
    sprite.move(offsetX, 0);
    collision.update(sprite.getSprite());
}

void Fireball::render(sf::RenderWindow& window) {
    sprite.draw(window);
    collision.draw(window); // Zeichne die Kollisionsbox, wenn aktiviert
}

sf::FloatRect Fireball::getBounds() const {
    return sprite.getGlobalBounds();
}

bool Fireball::checkCollision(const sf::FloatRect& otherBounds) const {
    return collision.checkCollision(otherBounds);
}

void Fireball::toggleCollisionBox() {
    collision.toggleCollisionBoxVisibility();
}

void Fireball::setCollisionBoxVisibility(bool visibility) {
    collision.setCollisionBoxVisibility(visibility);
}

void Fireball::clear()
{
    sprite.clear();
}
