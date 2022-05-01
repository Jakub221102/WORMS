#include "game_object.h"

GR::GameObject::GameObject(std::vector<std::pair<float, float>> vertices, std::string texture_path, float x, float y, float rotation)
	: shape(vertices.size()), vertices(vertices), texture_path(texture_path) {
	sf::Texture texture;
	texture.loadFromFile(texture_path);
	shape.setPosition({ x, y });
	shape.setRotation(rotation);
	shape.setTexture(&texture);
	for (size_t i = 0; i < vertices.size(); i++) {
		shape.setPoint(i, sf::Vector2f(vertices[i].first, vertices[i].second));
	}
}

GR::GameObject::GameObject(std::vector<std::pair<float, float>> vertices, std::string texture_path, sf::Vector2f position, float rotation)
	: GameObject(vertices, texture_path, position.x, position.y, rotation) {

}

sf::Vector2f GR::GameObject::getPosition() const {
	return shape.getPosition();
}

void GR::GameObject::setPosition(const sf::Vector2f& position) {
	this->shape.setPosition(position);
}

void GR::GameObject::setRotation(float angle) {
	this->shape.setRotation(angle);
}

void GR::GameObject::setScale(const sf::Vector2f& scale) {
	this->shape.setScale(scale);
}
