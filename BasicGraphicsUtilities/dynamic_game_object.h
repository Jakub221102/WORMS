#pragma once

#include "static_game_object.h"

namespace GR {
	class DynamicObject : public virtual StaticObject {
	protected:
		std::unique_ptr<DynamicModel> box2dModel;
	public:
		DynamicObject(b2World& world, const float& time, std::vector<std::pair<float, float>> vertices, std::string texture_path, bool noRotation = false);
		void setRotation(float angle) = delete;
		void setScale(float x, float y) = delete;
		void setScale(const sf::Vector2f& scale) = delete;
		void rotate(float angle) = delete;

		void setPosition(float x, float y, float angle);
		void setPosition(const sf::Vector2f& position, float angle);
		void setRotationSpeed(float speed);
		void translate(float x, float y);
		void translate(const sf::Vector2f& vec);
		void putVelocity(float x, float y);
		void putVelocity(const sf::Vector2f& vec);
		void putForceToCenter(float x, float y);
		void putForceToCenter(const sf::Vector2f& vec);
		void update();
	};
}