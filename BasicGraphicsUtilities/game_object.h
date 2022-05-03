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
		std::vector<std::unique_ptr<GameObject>> children;
		const float& deltaTime;
		GR::RealTimeInputManager<sf::Keyboard::Key, GR::GameObject> inputManager;
	public:
		GameObject(const float& time, std::vector<std::pair<float, float>> vertices, std::string texture_path, float x=0.0f, float y=0.0f, float rotation = 0.0f);
		GameObject(const float& time, std::vector<std::pair<float, float>> vertices, std::string texture_path, sf::Vector2f position, float rotation = 0.0f);
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

		// Game script

		float power = 200.0f;
		float rotPower = 90.0f;
		sf::Vector2f up = sf::Vector2f(0.0f, -1.0f);
		sf::Vector2f right = sf::Vector2f(1.0f, 0.0f);

		void addKeyBinding(sf::Keyboard::Key key, void (GR::GameObject::* pointer)()) {
			inputManager.addBinding(key, pointer);
		}

		void moveRight() {
			//float timerr = 10;
			translate(deltaTime*sf::Vector2f(40.0f, 0.0f));
		}

		void moveLeft() {
			//float timerr = 10;
			translate(deltaTime * sf::Vector2f(-40.0f, 0.0f));
		}

		void moveUp() {
			//float timerr = 10;
			translate(deltaTime * power * up);
		}

		void moveDown() {
			//float timerr = 10;
			translate(deltaTime * sf::Vector2f(0.0f, 40.0f));
			std::cout << deltaTime << std::endl;
		}
		# define PI           3.14159265358979323846f
		const float m = PI / 180.0f;
		void rotateLeft() {
			up = sf::Vector2f(
				up.x * std::cos(deltaTime * rotPower * m) - up.y * std::sin(deltaTime * rotPower * m),
				up.x * std::sin(deltaTime * rotPower * m) + up.y * std::cos(deltaTime * rotPower * m)
			);
			rotate(deltaTime * rotPower);
		}

		void rotateRight() {
			up = sf::Vector2f(
				up.x * std::cos(-deltaTime * rotPower * m) - up.y * std::sin(-deltaTime * rotPower * m),
				up.x * std::sin(-deltaTime * rotPower * m) + up.y * std::cos(-deltaTime * rotPower * m)
			);
			rotate(-deltaTime * rotPower);
		}

		void update() {
			inputManager.listenAndUseAll(*this);
		}
	};
}