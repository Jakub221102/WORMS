#include "static_animated_relative_object.h"

GR::StaticAnimatedRelativeObject::StaticAnimatedRelativeObject(const float& time, std::vector<std::pair<float, float>> vertices, const std::string& texture_path)
	: StaticAnimatedObject(time, vertices, texture_path), StaticObject(time, vertices, texture_path) {

}

void GR::StaticAnimatedRelativeObject::attachViewAndZoom(GR::Window& window) {
	winPointer = &window;
}

void GR::StaticAnimatedRelativeObject::update() {
	if (winPointer) {
		sf::FloatRect viewRect = winPointer->getViewRect();
		float zoom = winPointer->getZoom();
		sf::Vector2f topLeft = { viewRect.left, viewRect.top };
		setScale(zoom, zoom);
		setPosition(topLeft + zoom * translation);
	}
	static_cast<StaticAnimatedObject&>(*this).update();
}

void GR::StaticAnimatedRelativeObject::setRelativeVector(float x, float y) {
	translation = { x, y };
}

void GR::StaticAnimatedRelativeObject::setRelativeVector(const sf::Vector2f& translation) {
	this->translation = { translation.x, translation.y };
}
