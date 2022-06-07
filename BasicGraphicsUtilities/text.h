#pragma once

#include "SFML/Graphics.hpp"
#include <string>

namespace GR {
	class Text {
		sf::Font font;
		sf::Text text;
		sf::Vector2f translation;
		std::string txt = "";
	public:
		Text(const std::string& txt="", std::string font_path="animacje/arial.ttf");
		void setScale(float x, float y);
		void setColor(unsigned char r, unsigned char g, unsigned char b);
		void setString(const std::string& text);
		void setRelativeTranslation(float x, float y);
		void setPosition(float x, float y);
		void setCharackterSize(unsigned int size);
		void setOrigin(float x, float y);
		sf::Vector2f getTranslation();
		std::string getString() const;
		sf::Text& getText();
		friend bool operator==(const GR::Text& first, const GR::Text& second);
	};
}