#include "static_animated_object.h"

GR::StaticAnimatedObject::StaticAnimatedObject(const float& time, std::vector<std::pair<float, float>> vertices, const std::string& texture_path) 
	: StaticObject(time, vertices, texture_path) {
}

void GR::StaticAnimatedObject::update() {
	if(animation)
		animation->updateAnimation(deltaTime, shape);

}

void GR::StaticAnimatedObject::addAnimation(const std::string& key, const std::string& texturePath, int count, float totalTime) {
	Animation animation(texturePath, count, totalTime);
	if (animations.find(key) == animations.end())
		animations.insert({ key, animation });
}

void GR::StaticAnimatedObject::setCurrentAnimation(const std::string& key, bool toContinue) {
	if (!toContinue && animation) animation->zeroAnimationTime();
	auto found = animations.find(key);
	if (found != animations.end()) {
		animation = &found->second;
		shape.setTexture(&animation->getTexture());
	}
	else {
		animation = nullptr;
		shape.setTexture(&texture.getTexture());
	}
}