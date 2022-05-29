#pragma once

#include "static_game_object.h"
#include "window.h"

namespace GR {
	class RelativeStaticObject : public GR::StaticObject {
		sf::Vector2f translation;
		sf::Vector2f textTranslation;
		GR::Window* winPointer;
		float* zoom;
	public:
		RelativeStaticObject(const float& time, std::vector<std::pair<float, float>> vertices, std::string texture_path);
		void attachViewAndZoom(GR::Window& window);
		void setRelativeVector(float x, float y);
		void setRelativeVector(const sf::Vector2f& translation);
		void update();
	};
}