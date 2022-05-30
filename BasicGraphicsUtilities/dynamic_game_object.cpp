#include "dynamic_game_object.h"

#define PI 3.14159265359f

GR::DynamicObject::DynamicObject(b2World& world, const float& time, std::vector<std::pair<float, float>> vertices, std::string texture_path)
	:StaticObject(time, vertices, texture_path) {
	float x = origin.x, y = origin.y;
	b2Vec2* verts = new b2Vec2[vertices.size()];

	for (auto& element : vertices) {
		element.second += (2.0f * (y - element.second));
	}
	for (int i = 0; i < vertices.size(); i++) {
		//verts[i] = sfmlToBox(vertices[vertices.size() - i - 1], origin.x, origin.y);
		verts[i] = { vertices[i].first - x, vertices[i].second - y };
	}
	box2dModel = std::make_unique<DynamicModel>(world, x, y, verts, vertices.size());
	delete[] verts;
}

void GR::DynamicObject::putVelocity(float x, float y) {
	box2dModel->putVelocity({ x, y });
}

void GR::DynamicObject::putVelocity(const sf::Vector2f& vec) {
	putVelocity(vec.x, vec.y);
}

void GR::DynamicObject::update() {
	b2Vec2 position = box2dModel->getPosition();
	static_cast<StaticObject&>(*this).setPosition(position.x, -position.y);
	float degreeAngle = -box2dModel->getAngle() * 180.0f / PI;
	static_cast<StaticObject&>(*this).setRotation(degreeAngle);
	if (text) {
		sf::Vector2f translation = text->getTranslation();
		text->setPosition(position.x + translation.x, -position.y + translation.y);
	}
	//std::cout << "BOX2D: " << position.x << ' ' << position.y << std::endl;
	//std::cout << "SFML: " << shape.getPosition().x << ' ' << shape.getPosition().y << std::endl;
}

void GR::DynamicObject::setPosition(float x, float y, float angle) {
	box2dModel->setNewPosition({ x, y }, angle * 180.0f / PI);
}

void GR::DynamicObject::setPosition(const sf::Vector2f& position, float angle) {
	setPosition(position.x, position.y, angle);
}

void GR::DynamicObject::setRotationSpeed(float speed) {
	box2dModel->setRotationSpeed(speed);
}

void GR::DynamicObject::translate(float x, float y) {
	box2dModel->transform({ x, y });
}

void GR::DynamicObject::translate(const sf::Vector2f& vec) {
	translate(vec.x, vec.y);
}

void GR::DynamicObject::putForceToCenter(float x, float y) {
	box2dModel->putForceToCenter({x, y});
}

void GR::DynamicObject::putForceToCenter(const sf::Vector2f& vec) {
	putForceToCenter(vec.x, vec.y);
}