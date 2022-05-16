#include "static_game_object.h"


GR::StaticObject::StaticObject(const float& time, std::vector<std::pair<float, float>> vertices, std::string texture_path)
	: shape(vertices.size()), vertices(vertices), texture(texture_path), origin{}, deltaTime(time){
	shape.setTexture(&texture.getTexture());
	for (size_t i = 0; i < vertices.size(); i++) {
		shape.setPoint(i, sf::Vector2f(vertices[i].first, vertices[i].second));
		origin.x += vertices[i].first;
		origin.y += vertices[i].second;
	}
	shape.setOrigin(origin.x/vertices.size(), origin.y/vertices.size());
	shape.move(origin.x / vertices.size(), origin.y / vertices.size());
}

sf::Vector2f GR::StaticObject::getPosition() const {
	return shape.getPosition();
}

void GR::StaticObject::setPosition(const sf::Vector2f& position) {
	shape.setPosition(position);
}

void GR::StaticObject::setPosition(float x, float y) {
	shape.setPosition({x, y});
}

void GR::StaticObject::setRotation(float angle) {
	shape.setRotation(angle);
}

void GR::StaticObject::setScale(const sf::Vector2f& scale) {
	shape.setScale(scale);
}

void GR::StaticObject::setScale(float x, float y) {
	shape.setScale({x, y});
}

void GR::StaticObject::rotate(float angle) {
	shape.rotate(angle);
}

void GR::StaticObject::translate(float x, float y) {
	shape.move(x, y);
}

void GR::StaticObject::translate(const sf::Vector2f& translation) {
	shape.move(translation);
}

sf::Drawable& GR::StaticObject::getShape() {
	return shape;
}