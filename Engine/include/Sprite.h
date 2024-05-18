#ifndef SPRITE_H
#define SPRITE_H

#include <SFML/Graphics.hpp>
#include <imgui.h>
#include <imgui-SFML.h>
#include "missing_fix.h"
#include "Collision.h"
#include "TextureManager.h"

#pragma region Texture Manager

#pragma endregion


class Sprite {
private:
    missing_fix engine_missing;
    TextureManager textureManager;
    bool showTexturePicker = false;

    sf::Texture texture;
    sf::Sprite sprite;
    Collision collision;
    float width;
    float height;
    float speed;
    bool showCollisionBox;
    sf::FloatRect collisionBox;

public:
    Sprite() : width(16), height(16), showCollisionBox(false), speed(0.3f)
    {
        setCollisionBox(getLocalBounds());
        setCollisionBoxSize(width, height);

        // Load Example Textures
        textureManager.initialize();
    }

#pragma region Base

    // Laden der Textur aus einer Datei
    bool loadTextureFromFile(const std::string& filename) {
        if (!texture.loadFromFile(filename)) {
            if (!engine_missing.load_missing_texture()) {
                return false;
            }
            texture = engine_missing.get_missing_texture(width, height);
        }

        sprite.setTexture(texture);
        collision.update(sprite);
        width = static_cast<float>(texture.getSize().x);
        height = static_cast<float>(texture.getSize().y);
        return true;
    }

    // Zeichnen der Sprite auf dem Render-Target
    void draw(sf::RenderWindow& window) {
        window.draw(sprite);
        collision.draw(window);
    }

    // Bewegung der Sprite
    void move(float offsetX, float offsetY) {
        sprite.move(offsetX, offsetY);
        collision.update(sprite);
    }
    void toggleCollisionBox() {
        showCollisionBox = !showCollisionBox;
    }
    bool checkCollision(const sf::FloatRect& otherBounds) const {
        return collisionBox.intersects(otherBounds);
    }

#pragma region ImGui
    void ImGuiStart()
    {
        ImGui::Begin("Sprite Control Panel");
    }
    void ImGuiStart(const char* name)
    {
        ImGui::Begin(name);
    }

    void ImGuiSpriteTexture()
    {
        // ImGui::Text("Texture:");
        // ImGui::ImageButton((sf::Texture*)texture.getNativeHandle(), ImVec2(64, 64));
        ImGui::Text("Texture:");
        if (ImGui::ImageButton((void*)(intptr_t)texture.getNativeHandle(), ImVec2(64, 64))) {
            showTexturePicker = true;
        }

        if (showTexturePicker) {
            bool open = true;
            if (ImGui::Begin("Select Texture", &open)) {
                for (size_t i = 0; i < textureManager.getTextureCount(); ++i) {
                    if (ImGui::ImageButton((void*)(intptr_t)textureManager.getTexture(i).getNativeHandle(), ImVec2(64, 64))) {
                        texture = textureManager.getTexture(i);
                        sprite.setTexture(texture);
                        showTexturePicker = false;
                    }
                    ImGui::SameLine();
                    ImGui::Text(textureManager.getTextureName(i).c_str());
                }
                ImGui::End();
            }
            if (!open) {
                showTexturePicker = false;
            }
        }

        
    }
    void ImGuiSpritePosition()
    {
        ImGui::Text("Position:");
        float pos[2] = { sprite.getPosition().x, sprite.getPosition().y };
        ImGui::DragFloat2("##Position", pos);
        sprite.setPosition(pos[0], pos[1]);

    }
    void ImGuiSpriteOrigin()
    {
        ImGui::Text("Origin:");
        float origin[2] = { sprite.getOrigin().x, sprite.getOrigin().y };
        ImGui::DragFloat2("##Origin", origin);
        sprite.setOrigin(origin[0], origin[1]);
    }
    void ImGuiSpriteScale()
    {
        ImGui::Text("Scale:");
        float scale[2] = { sprite.getScale().x, sprite.getScale().y };
        ImGui::DragFloat2("##Scale", scale);
        sprite.setScale(scale[0], scale[1]);
    }
    void ImGuiSpriteRotation()
    {
        ImGui::Text("Rotation:");
        float rotation = sprite.getRotation();
        ImGui::DragFloat("##Rotation", &rotation);
        sprite.setRotation(rotation);
    }
    void ImGuiSpriteCollision()
    {
        if (ImGui::Checkbox("Show Collision Box", &showCollisionBox)) {
            // Do something when checkbox state changes
            collision.setCollisionBoxVisibility(showCollisionBox);
        }

        if (showCollisionBox) {
            ImGui::Text("Collision Box Size:");
            float boxSize[2] = { collisionBox.width, collisionBox.height };
            if (ImGui::DragFloat2("##CollisionBoxSize", boxSize)) {
                setCollisionBoxSize(boxSize[0], boxSize[1]);
            }
        }
    }

    void ImGuiEnd()
    {
        ImGui::End();
    }
#pragma endregion

#pragma endregion

#pragma region Setter

    void setSpeed(float newSpeed)
    {
        speed = newSpeed;
    }
    void setCollisionBoxSize(float width, float height) {
        collisionBox.width = width;
        collisionBox.height = height;
    }
    void setCollisionBox(const sf::FloatRect& box) {
        collisionBox = box;
    }
    void setPosition(float x, float y) {
        sprite.setPosition(x, y);
        collision.update(sprite);
    }

    void setOrigin(float x, float y) {
        sprite.setOrigin(x, y);
        collision.update(sprite);
    }

    void setScale(float x, float y) {
        sprite.setScale(x, y);
        collision.update(sprite);
    }
    void setRotation(float angle) {
        sprite.setRotation(angle);
        collision.update(sprite);
    }
    void setTextureRect(const sf::IntRect& rect) {
        sprite.setTextureRect(rect);
        collision.update(sprite);
    }

    void setColor(const sf::Color& color) {
        sprite.setColor(color);
    }


#pragma endregion

#pragma region Getter


    Collision& getCollision()
    {
        return collision;
    }
    float getSpeed()
    {
        return speed;
    }
    sf::Sprite getSprite() const {
        return sprite;
    }
    float getWidth() const {
        return width;
    }

    float getHeight() const {
        return height;
    }
    sf::Transform getTransform() const {
        return sprite.getTransform();
    }
    sf::FloatRect getLocalBounds() const {
        return sprite.getLocalBounds();
    }
    sf::Vector2f getPosition() const {
        return sprite.getPosition();
    }

    sf::FloatRect getGlobalBounds() const {
        return sprite.getGlobalBounds();
    }

#pragma endregion


    // Andere benutzerdefinierte Funktionen hier hinzufügen, je nach Bedarf
};


#endif // !SPRITE_H
