#ifndef ENGINE_MISSING_H
#define ENGINE_MISSING_H

#include <SFML/Graphics.hpp>
#include <iostream>

class missing_fix
{
public:
	
	sf::Texture get_missing_texture(float width, float height)
	{
		if (!load_missing_texture()) {
			std::cerr << "Could not load missing_texture.png" << std::endl;
		}
		return scalePlaceholderTexture(t_texture_missing, width, height);
	}
	bool load_missing_texture()			// Method to replace missing texture with engine placeholder texture
	{
		if(!t_texture_missing.loadFromFile("Assets/Engine/Textures/missing_texture.png"))
		{
			std::cout << "Could not load missing_texture.png" << std::endl;
			return false;
		}
		return true;
	}

	std::string get_missing_texture_path() const
	{
		return PLACEHOLDER_TEXTURE;
	}

private:
	sf::Texture t_texture_missing;					// Textures for Objects, Sprites utc when they are not found
	const std::string PLACEHOLDER_TEXTURE = "Assets/Engine/Textures/missing_texture.png";

	sf::Texture scalePlaceholderTexture(const sf::Texture& placeholder, float targetWidth, float targetHeight) {
		sf::Vector2u originalSize = placeholder.getSize();
		float scaleX = targetWidth / static_cast<float>(originalSize.x);
		float scaleY = targetHeight / static_cast<float>(originalSize.y);

		sf::RenderTexture renderTexture;
		renderTexture.create(static_cast<unsigned int>(targetWidth), static_cast<unsigned int>(targetHeight));

		sf::Sprite tempSprite(placeholder);
		tempSprite.setScale(scaleX, scaleY);

		renderTexture.clear(sf::Color::Transparent);
		renderTexture.draw(tempSprite);
		renderTexture.display();

		return renderTexture.getTexture();
	}
};

#endif // !
