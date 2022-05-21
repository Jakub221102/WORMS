#pragma once

#include "SFML/Graphics.hpp"

#include <string>

namespace GR {
	class Texture {
	protected:
		sf::Texture texture;
		std::string filePath;
	public:
		Texture(const std::string& filePath);
		sf::Texture& getTexture();
	};
}