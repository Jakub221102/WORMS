#pragma once

#include "animation.h"
#include <unordered_map>
#include "static_animated_object.h"
#include "window.h"


namespace GR {
	class StaticAnimatedRelativeObject : public StaticAnimatedObject {
	protected:
		sf::Vector2f translation;
		sf::Vector2f textTranslation;
		GR::Window* winPointer;
		float* zoom;
	public:
		StaticAnimatedRelativeObject(const float& time, std::vector<std::pair<float, float>> vertices, const std::string& texture_path);
		void attachViewAndZoom(GR::Window& window);
		void setRelativeVector(float x, float y);
		void setRelativeVector(const sf::Vector2f& translation);
		void update();
	};
}