#include "sample_static_physical_object.h"
#define PI 3.14159265359f


GR::SampleStaticPhysicalObject::SampleStaticPhysicalObject(b2World& world, const float& time, std::vector<std::pair<float, float>> vertices, std::string texture_path)
	:StaticObject(time, vertices, texture_path) {
	float x = origin.x, y = origin.y;
	b2Vec2* verts = new b2Vec2[vertices.size()];

	for (auto& element : vertices) {
		element.second += (2.0f * (y - element.second));
	}
	for (int i = 0; i < vertices.size(); i++) {
		//verts[i] = sfmlToBox(vertices[vertices.size() - i - 1], origin.x, origin.y);
		verts[i] = { vertices[i].first - x, -(vertices[i].second - y) };
	}
	box2dModel = std::make_unique<StaticModel>(world, x, -y, verts, vertices.size());
	delete[] verts;
	//b2Vec2 position = box2dModel->getPosition();
	//static_cast<StaticObject&>(*this).setPosition(position.x, -position.y);
	//float degreeAngle = box2dModel->getAngle() * 180.0f / PI;
	//static_cast<StaticObject&>(*this).setRotation(degreeAngle);
}