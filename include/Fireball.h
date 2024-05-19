#ifndef FIREBALL_H
#define FIREBALL_H

#include <SFML/Graphics.hpp>
#include "Sprite.h"
#include "Collision.h"

class Fireball {
private:
    Sprite sprite;
    bool moveRight;
    float speed;
    Collision collision;

public:
    Fireball(float startX, float startY, bool moveRight, float speed);
    Fireball(const Fireball& other) {
        // Kopieren Sie hier die Eigenschaften von 'other' in diese Instanz
    }
    Fireball& operator=(const Fireball& other) {
        // Prüfen, ob es sich um dieselbe Instanz handelt
        if (this == &other)
            return *this;

        // Kopieren Sie hier die Eigenschaften von 'other' in diese Instanz

        return *this;
    }

    void update(float deltaTime);
    void render(sf::RenderWindow& window);
    sf::FloatRect getBounds() const;
    bool checkCollision(const sf::FloatRect& otherBounds) const;

    void toggleCollisionBox();
    void setCollisionBoxVisibility(bool visibility);
    void clear();

    void renderImGui()
    {
        sprite.ImGuiStart("Fireball Controller");
        sprite.ImGuiSpriteTexture();
        sprite.ImGuiEnd();
    }
};

#endif // FIREBALL_H
