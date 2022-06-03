#pragma once
#include "static_animated_object.h"
#include "dynamic_game_object.h"

namespace GR {
	class DynamicAnimatedObject : public DynamicObject, public StaticAnimatedObject {
	public:
		DynamicAnimatedObject(b2World& world, const float& time, std::vector<std::pair<float, float>> vertices, std::string texture_path, bool noRotation = false)
			: DynamicObject(world, time, vertices, texture_path, noRotation), StaticObject(time, vertices, texture_path), StaticAnimatedObject(time, vertices, texture_path){

		}
		void update(){
			(static_cast<DynamicObject&>(*this)).update();
			(static_cast<StaticAnimatedObject&>(*this)).update();
		}
	};
}