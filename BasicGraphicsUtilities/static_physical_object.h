#pragma once
#include "static_game_object.h"
#include "C:\Users\elPrezes\source\repos\WORMS\proi_projekt_2022l_lab205_ejzak_kowalski_kowalczyk_wozniak\box2d_code\objects.h"

namespace GR {
	class StaticPhysicalObject : public GR::StaticObject {
		std::unique_ptr<StaticModel> box2dModel;
	public:
		StaticPhysicalObject(b2World& world, const float& time, std::vector<std::pair<float, float>> vertices, std::string texture_path);
	};
}