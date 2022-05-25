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
	//wormsWindow.setFramesPerSecond(60);
	wormsWindow.setKeyArguments(sf::Keyboard::A, {10.0f});
	wormsWindow.setViewBorder(0, 0.0f, 1920.0f, 1080.0f);
	wormsWindow.setView(-1000.0f, -1000.0f, 2000.0f, 2000.0f); // view does not fit in viewBorder so view is set to viewBorder by default
	wormsWindow.setZoomSpeed(4.0f);

	std::vector<std::pair<float, float>> vertices {
		{300.0f, 300.0f},
		{700.0f, 300.0f},
		{700.0f, 900.0f},
		//{550.0f, 900.0f},
		{300.0f, 900.0f}
	};
	std::vector<std::pair<float, float>> vertices2{
		{500.0f, 60.0f},
		{900.0f, 60.0f},
		{900.0f, 140.0f},
		{500.0f, 140.0f}
	};
	b2Vec2 gravity(0.0f, -10.0f);
	b2World world(gravity);

	b2BodyDef groundBodyDef;
	groundBodyDef.position.Set(10.0f, -10.0f);

	b2Body* groundBody = world.CreateBody(&groundBodyDef);
	b2PolygonShape groundBox;
	groundBox.SetAsBox(100.0f, 5.0f);
	groundBody->CreateFixture(&groundBox, 0.0f);


	GR::DynamicObject obj(world, deltaTime, vertices, "pingwin.png");
	GR::DynamicObject ob(world, deltaTime, vertices2, "pingwin.png");
	//obj.putVelocity(-10000000.0f, -10.0f);
	//obj.addAnimation("IDLE", "pingwin.png", 4, 4.0f);
	//obj.addAnimation("WORM", "robole.png", 4, 3.0f);
	//obj.setCurrentAnimation("IDLE");
	sf::Clock ck;
	ck.restart();
	//obj.translate({ 500.0f, 0.0f });
	//obj.setPosition({ 0.0f, 0.0f });
	float global = 0.0f;
	//obj.setScale({ 1.5f, 1.5f });
	while (!wormsWindow.isDone()) {
		deltaTime = ck.restart().asSeconds();
		wormsWindow.setBackGroundColor(200, 200, 200);
		obj.update();
		ob.update();
		//obj.rotate(deltaTime);
		wormsWindow.update();							// 10 is a random value for now
		//std::cout << wormsWindow.getMouseWorldCoords().x << ' ' << wormsWindow.getMouseWorldCoords().y << std::endl;
		wormsWindow.draw(obj);
		wormsWindow.draw(ob);
		wormsWindow.endDraw();
		int a;
		//std::cin >> a
		b2Vec2 pos = obj.box2dModel->getPosition();
		if (pos.y < 0)
		{
			obj.box2dModel->transform({ 0, 10 });
		}
		world.Step(deltaTime, 6, 2);
	}
	return 0;
}