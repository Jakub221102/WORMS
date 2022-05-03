#include "animated_object.h"

GR::AnimatedObject::AnimatedObject(const float& time, std::vector<std::pair<float, float>> vertices, std::string texture_path, int count, float totalTime) 
	: GameObject(time, vertices, texture_path, {0, 0}, 0), animation(texture_path, count, totalTime) {

}

void GR::AnimatedObject::update() {
	animation.updateAnimation(deltaTime, shape);
}