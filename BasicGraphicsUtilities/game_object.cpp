#include "game_object.h"

GR::GameObject::GameObject(std::vector<std::pair<float, float>> vertices, std::string texture_path, float x, float y, float rotation)
	: shape(vertices.size()), vertices(vertices), texture(texture_path), origin{} {
	shape.setPosition({ x, y });
	shape.setRotation(rotation);
	shape.setTexture(texture.getPixels());
	for (size_t i = 0; i < vertices.size(); i++) {
		shape.setPoint(i, sf::Vector2f(vertices[i].first, vertices[i].second));
		origin.x += vertices[i].first;
		origin.y += vertices[i].second;
	}
	shape.setOrigin(origin.x/vertices.size(), origin.y/vertices.size());
	shape.move(origin.x / vertices.size(), origin.y / vertices.size());
}

GR::GameObject::GameObject(std::vector<std::pair<float, float>> vertices, std::string texture_path, sf::Vector2f position, float rotation)
	: GameObject(vertices, texture_path, position.x, position.y, rotation) {

}

sf::Vector2f GR::GameObject::getPosition() const {
	return shape.getPosition();
}

void GR::GameObject::setPosition(const sf::Vector2f& position) {
	shape.setPosition(position);
}

void GR::GameObject::setPosition(float x, float y) {
	shape.setPosition({x, y});
}

void GR::GameObject::setRotation(float angle) {
	shape.setRotation(angle);
}

void GR::GameObject::setScale(const sf::Vector2f& scale) {
	shape.setScale(scale);
}

void GR::GameObject::setScale(float x, float y) {
	shape.setScale({x, y});
}

void GR::GameObject::rotate(float angle) {
	shape.rotate(angle);
}

void GR::GameObject::translate(float x, float y) {
	shape.move(x, y);
}

void GR::GameObject::translate(const sf::Vector2f& translation) {
	shape.move(translation);
}

sf::Drawable& GR::GameObject::getShape() {
	return shape;
}
