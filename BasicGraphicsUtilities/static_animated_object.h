#pragma once

#include "animation.h"
#include <unordered_map>
#include "static_game_object.h"


namespace GR {
	class StaticAnimatedObject : public virtual StaticObject {
	protected:
		Animation* animation = nullptr;
		std::unordered_map<std::string, Animation> animations;
	public:
		StaticAnimatedObject(const float& time, std::vector<std::pair<float, float>> vertices, const std::string& texture_path);
		void addAnimation(const std::string& key, const std::string& texturePath, int count, float totalTime);
		void setCurrentAnimation(const std::string& key, bool toContinue = false);
		void zeroAnimation();
		void update();
	};
}
