#ifndef TEXTURE_MANAGER_H
#define TEXTURE_MANAGER_H

#include <vector>
#include <SFML/Graphics.hpp>
#include <imgui.h>
#include <imgui-SFML.h>

struct TextureManager {
    std::vector<sf::Texture> textures;
    std::vector<std::string> textureNames;

    bool loadTexture(const std::string& filePath, const std::string& fileName) {
        sf::Texture texture;
        if (texture.loadFromFile(filePath)) {
            textures.push_back(texture);
            textureNames.push_back(fileName);
            return true;
        }
        return false;
    }

    sf::Texture& getTexture(size_t index) {
        return textures[index];
    }

    size_t getTextureCount() const {
        return textures.size();
    }

    const std::string& getTextureName(size_t index) const {
        return textureNames[index];
    }

    void initialize()
    {
        loadTexture("Assets/Game/Star_Red.png", "Red Star");
        loadTexture("Assets/Game/Star_Green.png", "Green Star");
        loadTexture("Assets/Engine/Textures/missing_texture.png", "MissingTexture");
    }

    void showEngineTextureAtlas(sf::Sprite sprite, sf::Texture& texture, bool showTexturePicker)
    {
        bool open = showTexturePicker;
        if (ImGui::Begin("Select Texture", &open)) {
            for (size_t i = 0; i < getTextureCount(); ++i) {
                if (ImGui::ImageButton((void*)(intptr_t)getTexture(i).getNativeHandle(), ImVec2(64, 64))) {
                    texture = getTexture(i);
                    sprite.setTexture(texture);
                    showTexturePicker = false;
                }
                ImGui::SameLine();
                ImGui::Text(getTextureName(i).c_str());
            }
            ImGui::End();
        }
        if (!open) {
            showTexturePicker = false;
        }
    }
};

#endif // !TEXTURE_MANAGER_H
