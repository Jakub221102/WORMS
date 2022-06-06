#pragma once
#include "static_game_object.h"
#include "objects.h"

namespace GR {
	class StaticPhysicalObject : public GR::StaticObject {
		std::unique_ptr<StaticModel> box2dModel;
	public:
		StaticPhysicalObject(b2World& world, const float& time, std::vector<std::pair<float, float>> vertices, std::string texture_path);
	};
}