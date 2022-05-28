#pragma once

#include "dynamic_animated_object.h"

class Worm : public GR::DynamicAnimatedObject {
	
public:
	Worm(b2World& world, const float& time, std::vector<std::pair<float, float>> vertices, std::string texture_path);
};

Worm::Worm(b2World& world, const float& time, std::vector<std::pair<float, float>> vertices, std::string texture_path) 
	: DynamicAnimatedObject(world, time, vertices, texture_path), StaticObject(time, vertices, texture_path){

}
