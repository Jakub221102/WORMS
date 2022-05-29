#include "static_object_relative.h"

GR::RelativeStaticObject::RelativeStaticObject(const float& time, std::vector<std::pair<float, float>> vertices, std::string texture_path)
	: StaticObject(time, vertices, texture_path), translation(sf::Vector2f()), winPointer() {
}

void GR::RelativeStaticObject::attachViewAndZoom(GR::Window& window) {
	winPointer = &window;
}

void GR::RelativeStaticObject::update() {
	if (winPointer) {
		sf::FloatRect viewRect = winPointer->getViewRect();
		float zoom = winPointer->getZoom();
		sf::Vector2f topLeft = { viewRect.left, viewRect.top };
		setScale(zoom, zoom);
		setPosition(topLeft + zoom * translation);
	}
}

void GR::RelativeStaticObject::setRelativeVector(float x, float y) {
	translation = { x, y };
}

void GR::RelativeStaticObject::setRelativeVector(const sf::Vector2f& translation) {
	this->translation = { translation.x, translation.y };
}

