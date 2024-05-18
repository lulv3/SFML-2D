#ifndef COLLISION_H
#define COLLISION_H

#include <SFML/Graphics.hpp>
#include "imgui.h"
#include "imgui-SFML.h"

class Collision {
private:
    sf::FloatRect collisionBox;
    bool showCollisionBox;

public:
    Collision() : showCollisionBox(false) {}

    // Setze die Position der Kollisionsbox basierend auf der Sprite-Position
    void update(const sf::Sprite& sprite) {
        collisionBox = sprite.getGlobalBounds();
    }

    // Überprüfe, ob eine Kollision mit einer anderen Kollisionsbox vorliegt
    bool checkCollision(const sf::FloatRect& otherBounds) const {
        return collisionBox.intersects(otherBounds);
    }

    // Setze die Kollisionsbox explizit
    void setCollisionBox(const sf::FloatRect& box) {
        collisionBox = box;
    }

    // Rückgabe der Kollisionsbox
    sf::FloatRect getCollisionBox() const {
        return collisionBox;
    }

    // Schalte die Sichtbarkeit der Kollisionsbox um
    void toggleCollisionBoxVisibility() {
        showCollisionBox = !showCollisionBox;
    }

    // Setze die Sichtbarkeit der Kollisionsbox
    void setCollisionBoxVisibility(bool visibility) {
        showCollisionBox = visibility;
    }

    // Zeichne die Kollisionsbox, wenn die Sichtbarkeit aktiviert ist
    void draw(sf::RenderWindow& window) const {
        if (showCollisionBox) {
            sf::RectangleShape rect(sf::Vector2f(collisionBox.width, collisionBox.height));
            rect.setPosition(collisionBox.left, collisionBox.top);
            rect.setFillColor(sf::Color::Transparent);
            rect.setOutlineThickness(1.f);
            rect.setOutlineColor(sf::Color::Red);
            window.draw(rect);
        }
    }

    // ImGui-Steuerungen für die Kollisionsbox-Eigenschaften
    void imguiControlPanel() {
        ImGui::Begin("Collision Control Panel");
        if (ImGui::Checkbox("Show Collision Box", &showCollisionBox)) {
            // Do something when checkbox state changes
        }

        ImGui::Text("Collision Box:");
        ImGui::Text("Left: %.2f, Top: %.2f, Width: %.2f, Height: %.2f",
            collisionBox.left, collisionBox.top, collisionBox.width, collisionBox.height);

        ImGui::End();
    }
};

#endif // !COLLISION_H
