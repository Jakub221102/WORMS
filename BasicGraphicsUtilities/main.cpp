#pragma once
#include <iostream>

#include "SFML/Graphics.hpp"
//#include "box2d/box2d.h"
#include "input_manager.h"

#include "window.h"
#include "static_animated_object.h"

float deltaTime;

int main() {
	GR::Window wormsWindow(deltaTime);
	wormsWindow.setKeyArguments(sf::Keyboard::A, {10.0f});
	wormsWindow.setViewBorder(200.0f, 200.0f, 800.0f, 800.0f);
	wormsWindow.setView(0.0f, 0.0f, 400.0f, 400.0f);
	wormsWindow.setZoomSpeed(4.0f);

	std::vector<std::pair<float, float>> vertices{
		{300.0f, 300.0f},
		{700.0f, 300.0f},
		{700.0f, 700.0f},
		{300.0f, 700.0f}
	};

	GR::StaticAnimatedObject obj(deltaTime, vertices, "pingwin.png");
	obj.addAnimation("IDLE", "pingwin.png", 4, 4.0f);
	obj.addAnimation("WORM", "robole.png", 4, 3.0f);
	obj.setCurrentAnimation("IDLE");
	sf::Clock ck;
	ck.restart();
	obj.translate({ 500.0f, 0.0f });
	obj.setPosition({ 600.0f, 400.0f });
	float global = 0.0f;
	obj.setScale({ 2.0f, 2.0f });
	while (!wormsWindow.isDone()) {
		deltaTime = ck.restart().asSeconds();
		wormsWindow.setBackGroundColor(200, 200, 200);
		obj.update();
		obj.rotate(deltaTime);
		wormsWindow.update(10);
		std::cout << wormsWindow.getMouseWorldCoords().x << ' ' << wormsWindow.getMouseWorldCoords().y << std::endl;
		wormsWindow.draw(obj);
		wormsWindow.endDraw();
	}
	return 0;
}