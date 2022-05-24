#include "dynamic_game_object.h"

GR::DynamicObject::DynamicObject(b2World& world, const float& time, std::vector<std::pair<float, float>> vertices, std::string texture_path)
	:StaticObject(time, vertices, texture_path) {
	float x = origin.x, y = origin.y;
	b2Vec2* verts = new b2Vec2[vertices.size()];
	for (int i = 0; i < vertices.size(); i++) {
		verts[i] = { vertices[i].first - x, vertices[i].second - y };
	}
	//b2Vec2 verts[4] = { b2Vec2(-2, 1), b2Vec2(-2, -1), b2Vec2(2, -1), b2Vec2(2, 1) };

	box2dModel = std::make_unique<DynamicModel>(world, x, y, verts, vertices.size());
	delete[] verts;
}
void GR::DynamicObject::putVelocity(float x, float y) {
	box2dModel->putVelocity({ x, y });
}

void GR::DynamicObject::update() {
	b2Vec2 position = box2dModel->getPosition();
	setPosition(position.x, -position.y);
	float degreeAngle = -box2dModel->getAngle() * 180.0f / 3.1415f;
	setRotation(degreeAngle);
	//std::cout << "BOX2D: " << position.x << ' ' << position.y << std::endl;
	//std::cout << "SFML: " << shape.getPosition().x << ' ' << shape.getPosition().y << std::endl;
}