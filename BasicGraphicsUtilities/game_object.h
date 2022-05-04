#include "SFML/Graphics.hpp"

#include "texture.h"
#include "input_manager.h"

#include <vector>
#include <string>
#include <memory>
#include <cmath>


namespace GR {
	class GameObject {
	protected:
		GR::Texture texture;
		sf::ConvexShape shape;
		sf::Vector2f origin;
		const std::vector<std::pair<float, float>> vertices;
		const float& deltaTime;
	public:
		GameObject(const float& time, std::vector<std::pair<float, float>> vertices, std::string texture_path);
		
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
}