#pragma once

#include "animation.h"
#include "game_object.h"

namespace GR {
	class AnimatedObject : public GR::GameObject {
	protected:
		Animation animation;
	public:
		AnimatedObject(const float& time, std::vector<std::pair<float, float>> vertices, std::string texture_path, int count, float totalTime);
		void update();
	};
}
