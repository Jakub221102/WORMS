#include "SFML/Graphics.hpp"

#include "texture.h"
#include "input_manager.h"
#include "objects.h"

#include <vector>
#include <string>
#include <memory>
#include <cmath>
#include <iostream>
#include <cmath>

b2Vec2 sfmlToBox(std::pair<float, float>&, float x = 0, float y = 0);
sf::Vector2f boxToSfml(b2Vec2&, float x = 0, float y = 0);

namespace GR {
	class StaticObject {
	protected:
		GR::Texture texture;
		sf::ConvexShape shape;
		sf::Vector2f origin;
		const std::vector<std::pair<float, float>> vertices;
		const float& deltaTime;
	public:
		StaticObject(const float& time, std::vector<std::pair<float, float>> vertices, std::string texture_path);
		
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
	};

	
	
	
	
	
	//class Worms : public 
	//{
	//protected:
	//Worms w;
	//public:
	//}
}

