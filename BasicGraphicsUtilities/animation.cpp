#pragma once

#include "animation.h"

GR::Animation::Animation(const std::string& filePath, int count, float totalTime) {
	setAnimation(filePath, count, totalTime);
}


void GR::Animation::setAnimation(const std::string& filePath, int count, float totalTime) {
	leftBorders.clear();
	texture.loadFromFile(filePath);
	texture.setSmooth(true);
	this->count = count;
	counter = 0;
	this->totalTime = totalTime;
	timeStep = totalTime / count;
	heigth = texture.getSize().y;
	for (int i = 0; i < count; i++) 
		leftBorders.push_back(static_cast<float>(i) * texture.getSize().x / static_cast<float>(count));
}
#include <iostream>

void GR::Animation::updateAnimation(float deltaTime, sf::Shape& object) {
	animationTime += deltaTime;
	float t = 0.0f;
	animationTime -= std::floor(animationTime / totalTime) * totalTime;
	counter = floor(animationTime / totalTime * count);
	/*while (animationTime > totalTime) animationTime -= totalTime;
	for (int i = 0; i < count; i++) {
		if (t <= animationTime && animationTime <= t + timeStep) counter = i;
		t += timeStep;
	}
	counter %= count;*/
	std::cout << counter << std::endl;
	sf::IntRect rectangle{leftBorders[counter], 0, leftBorders[1], heigth};
	object.setTextureRect(rectangle);
}