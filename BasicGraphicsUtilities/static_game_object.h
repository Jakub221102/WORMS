#include "SFML/Graphics.hpp"

#include "texture.h"
#include "input_manager.h"
#include "../box2d_code/objects.h"

#include <vector>
#include <string>
#include <memory>
#include <cmath>
#include <iostream>
#include <cmath>

b2Vec2 sfmlToBox(std::pair<float, float>&, float x=0, float y=0);

sf::Vector2f boxToSfml(b2Vec2&, float x=0, float y=0);

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

	class DynamicObject : public StaticObject {
	protected:
		std::unique_ptr<DynamicModel> box2dModel;
	public:
		DynamicObject(b2World& world, const float& time, std::vector<std::pair<float, float>> vertices, std::string texture_path) 
			:StaticObject(time, vertices, texture_path) {
			float x = origin.x, y = origin.y;
			b2Vec2* verts = new b2Vec2[vertices.size()];
			for (int i = 0; i < vertices.size(); i++) {
				verts[vertices.size()-i-1] = sfmlToBox(vertices[i], origin.x, origin.y);
			}
			std::pair<float, float> pOrigin = { x, y };
			b2Vec2 boxOrigin = sfmlToBox(pOrigin);
			box2dModel = std::make_unique<DynamicModel>(world, boxOrigin.x, boxOrigin.y, verts, vertices.size());
			delete[] verts;
		}
		void putVelocity(float x, float y) {
			box2dModel->putVelocity({ x, y });
		}

		void update() {
			b2Vec2 position = box2dModel->getPosition();
			sf::Vector2f vec = boxToSfml(position);
			setPosition(vec.x, -vec.y);
			float degreeAngle = -box2dModel->getAngle() * 180.0f / 3.1415f;
			setRotation(degreeAngle);
			std::cout << "BOX2D: " << position.x << ' ' << position.y << std::endl;
			std::cout << "SFML: " << shape.getPosition().x << ' ' << shape.getPosition().y << std::endl;
		}
	};
	
	
	
	
	//class Worms : public 
	//{
	//protected:
	//Worms w;
	//public:
	//}
}