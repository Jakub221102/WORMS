#pragma once

#include "SFML/Graphics.hpp"

#include <string>

namespace GR {
	class Texture {
		sf::Texture texture;
		std::string filePath;
	public:
		Texture(const std::string& filePath, sf::IntRect singleFrame=sf::IntRect(), unsigned int count=1);
		sf::Texture* getPixels();
	};
}