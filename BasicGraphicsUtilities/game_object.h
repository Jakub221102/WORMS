#include "SFML/Graphics.hpp"
#include <vector>
#include <string>

namespace GR {
	class GameObject {
		sf::Texture texture;
		std::string texture_path;
		sf::ConvexShape shape;
		const std::vector<std::pair<float, float>> vertices;
	public:
		GameObject(std::vector<std::pair<float, float>> vertices, std::string texture_path, float x, float y, float rotation = 0.0f);
		GameObject(std::vector<std::pair<float, float>> vertices, std::string texture_path, sf::Vector2f position, float rotation = 0.0f);
		sf::Vector2f getPosition() const;
		void setPosition(const sf::Vector2f& position);
		void setRotation(float angle);
		void setScale(const sf::Vector2f& scale);
		void render();
	};
}