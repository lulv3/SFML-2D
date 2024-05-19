#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>
#include <string>
#include <imgui.h>
#include <imgui-SFML.h>
#include "Sprite.h"
#include "Input.h"
#include "Collision.h"

class Player {
public:
    Player();
    void move(const sf::Vector2f& direction);
    void draw(sf::RenderWindow& window);
    sf::FloatRect getBounds() const;
    sf::FloatRect getCollisionBox() const;
    bool checkCollision(const sf::FloatRect& otherBounds) const;

    void toggleCollisionBox();
    sf::Sprite getSprite() const {
        return sprite.getSprite();
    }
    void renderImGui();
    void handleInput();


    void tageDamage(int dmg);
    bool isPlayerDead();
    int getPlayerHealth();
    void setSize(float sizeX, float sizeY);
    void update();
    void setCollisionBoxVisibility(bool visibility);

private:
    Sprite sprite;
    sf::Texture texture;
    Collision collision;

    float speed = 0.3f;
    float width;
    float height;
    int health;
    bool isDead;
};

#endif
