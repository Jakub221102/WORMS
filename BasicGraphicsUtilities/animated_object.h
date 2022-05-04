#pragma once

#include "animation.h"
#include "game_object.h"

namespace GR {
	class AnimatedObject : public GR::GameObject {
	protected:
		Animation* animation = nullptr;
		std::unordered_map<std::string, Animation> animations;
	public:
		AnimatedObject(const float& time, std::vector<std::pair<float, float>> vertices, const std::string& texture_path);
		void addAnimation(const std::string& key, const std::string& texturePath, int count, float totalTime);
		void setCurrentAnimation(const std::string& key, bool toContinue = false);
		void update();
	};
}
