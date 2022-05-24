#pragma once

#include "static_game_object.h"

namespace GR {
	class DynamicObject : public virtual StaticObject {
	protected:
		std::unique_ptr<DynamicModel> box2dModel;
	public:
		DynamicObject(b2World& world, const float& time, std::vector<std::pair<float, float>> vertices, std::string texture_path);
		void putVelocity(float x, float y);

		void update();
	};
}