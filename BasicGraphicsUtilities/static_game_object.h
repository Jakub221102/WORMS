#pragma once
#include "SFML/Graphics.hpp"

#include "objects.h"
#include "texture.h"
#include "input_manager.h"
#include "text.h"

#include <vector>
#include <string>
#include <memory>
#include <cmath>
#include <iostream>
#include <cmath>


namespace GR {
	class StaticObject {
	protected:
		GR::Text* text;
		GR::Texture texture;
		sf::ConvexShape shape;
		sf::Vector2f origin;
		const std::vector<std::pair<float, float>> vertices;
		const float& deltaTime;
	public:
		StaticObject(const float& time, std::vector<std::pair<float, float>> vertices, std::string texture_path);
		void attachText(GR::Text& tekst);
		std::string getString() const;
		sf::Vector2f getPosition() const;
		void setPosition(const sf::Vector2f& position);
		void setPosition(float x, float y);
		void setRotation(float angle);
		void setScale(const sf::Vector2f& scale);
		void setScale(float x, float y);
		void rotate(float angle);
		void translate(const sf::Vector2f& translation);
		void translate(float x, float y);
		sf::Drawable& getShape();
		sf::Text& getText();
	};
	
	//class Worms : public 
	//{
	//protected:
	//Worms w;
	//public:
	//}
}

