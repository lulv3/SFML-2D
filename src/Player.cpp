#include "Player.h"
#include "Window.h"

Player::Player() : health(3), isDead(false) {
    sprite.loadTextureFromFile("Assets/Game/Star_Green.png");
    sprite.setScale(5, 5);
    collision.update(sprite.getSprite());
}

void Player::move(const sf::Vector2f& direction) {
    sprite.move(direction.x, direction.y);
    collision.update(sprite.getSprite());
}

void Player::draw(sf::RenderWindow& window) {
    window.draw(sprite.getSprite());
    collision.draw(window); // Zeichne die Kollisionsbox, wenn aktiviert
}
bool Player::checkCollision(const sf::FloatRect& otherBounds) const {
    return collision.checkCollision(otherBounds);
}

void Player::toggleCollisionBox() {
    collision.toggleCollisionBoxVisibility();
}

void Player::setCollisionBoxVisibility(bool visibility) {
    collision.setCollisionBoxVisibility(visibility);
}


sf::FloatRect Player::getBounds() const {
    return sprite.getGlobalBounds();
}
void Player::update()
{
    collision.update(sprite.getSprite());
}
void Player::handleInput() {
    if (!isDead)
    {
        sf::Vector2f movement(0.0f, 0.0f);


        if (Input::isKeyPressed(Input::W)) {
            movement.y -= speed;
            move(movement);
        }
        if (Input::isKeyPressed(Input::S)) {
            movement.y += speed;
            move(movement);
        }
        if (Input::isKeyPressed(Input::A)) {
            movement.x -= speed;
            move(movement);
        }
        if (Input::isKeyPressed(Input::D)) {
            movement.x += speed;
            move(movement);
        }
    }
}


void Player::tageDamage(int dmg)
{
    health -= dmg;
}

bool Player::isPlayerDead()
{
    if (health <= 0 || health == 0)
        isDead = true;

    return isDead;
}
int Player::getPlayerHealth()
{
    return health;
}

void Player::renderImGui() {
    sprite.ImGuiStart("Player Controller");
    sprite.ImGuiSpriteTexture();
    ImGui::NewLine();
    ImGui::SliderFloat("Speed:", &speed, 0.0f, 5.0f);
    ImGui::NewLine();
    sprite.ImGuiSpritePosition();
    sprite.ImGuiSpriteOrigin();
    sprite.ImGuiSpriteRotation();
    sprite.ImGuiSpriteScale();
    ImGui::NewLine();
    ImGui::InputInt("Health: ", &health, 0, 100);
    if (ImGui::Button("Revive Player"))
    {
        health = 3;
        isDead = false;
    }
    ImGui::NewLine();
    sprite.ImGuiSpriteCollision();
    sprite.ImGuiEnd();
}
