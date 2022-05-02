#include "SFML/Graphics.hpp"

#include "texture.h"
#include "input_manager.h"

#include <vector>
#include <string>
#include <memory>


namespace GR {
	class GameObject {
	protected:
		GR::Texture texture;
		sf::ConvexShape shape;
		sf::Vector2f origin;
		const std::vector<std::pair<float, float>> vertices;
		std::vector<std::unique_ptr<GameObject>> children;
	public:
		GameObject(std::vector<std::pair<float, float>> vertices, std::string texture_path, float x, float y, float rotation = 0.0f);
		GameObject(std::vector<std::pair<float, float>> vertices, std::string texture_path, sf::Vector2f position, float rotation = 0.0f);
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