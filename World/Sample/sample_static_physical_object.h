#pragma once
#include "../../BasicGraphicsUtilities/static_game_object.h"
#include "../../box2d_code/objects.h"

namespace GR {
	class SampleStaticPhysicalObject : public GR::StaticObject {
		std::unique_ptr<StaticModel> box2dModel;
	public:
		SampleStaticPhysicalObject(b2World& world, const float& time, std::vector<std::pair<float, float>> vertices, std::string texture_path);
	};
}