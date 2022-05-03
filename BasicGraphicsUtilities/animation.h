#pragma once

#include "texture.h"

namespace GR {
	class Animation {
		sf::Texture texture;
		int count;
		int counter;
		float totalTime;
		float timeStep;
		int heigth;
		float animationTime{};
		std::vector<int> leftBorders;
	public:
		Animation(const std::string& filePath, int count, float totalTime);
		void setAnimation(const std::string& filePath, int count, float totalTime);
		void updateAnimation(float deltaTime, sf::Shape& object);
	};
}
