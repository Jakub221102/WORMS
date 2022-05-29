#pragma once
#include <iostream>

#include "Graphics.hpp"
#include "box2d.h"
#include "input_manager.h"

#include "window.h"
#include "static_animated_object.h"
#include "dynamic_game_object.h"

float deltaTime;

int main() {
	GR::Window wormsWindow(deltaTime);
	GR::Text tekst("ala ma kota");
	tekst.setPosition(600.0f, 600.0f);
	tekst.setRelativeTranslation(0.0f, 0.0f);
	tekst.setColor(255, 0, 0);
	tekst.setCharackterSize(40);
	//wormsWindow.setFramesPerSecond(60);
	wormsWindow.setKeyArguments(sf::Keyboard::A, { 10.0f });
	wormsWindow.setViewBorder(0, 0.0f, 1920.0f, 1080.0f);
	wormsWindow.setView(0, 0.0f, 1920.0f, 1080.0f); // view does not fit in viewBorder so view is set to viewBorder by default
	wormsWindow.setZoomSpeed(200.0f);
	std::vector<std::pair<float, float>> vertices{
		{300.0f, 300.0f},
		{700.0f, 300.0f},
		{700.0f, 900.0f},
		//{550.0f, 900.0f},
		{300.0f, 900.0f}
	};
	std::vector<std::pair<float, float>> vertices2{
		{540, 60.0f},
		{940.0f, 60.0f},
		{940.0f, 140.0f},
		{540.0f, 140.0f}
	};

	std::vector<std::pair<float, float>> vertices3{
		{400.0f, -100.0f * sqrt(3) - 200.0f},


		//{500.0f, -200.0f},
		//{400.0f, -200.0f},
		{350.0f, -50.0f * sqrt(3) - 200.0f},
		{550.0f, -50.0f * sqrt(3) - 200.0f},
		{500.0f, -100.0f * sqrt(3) - 200.0f},
		//{400.0f, -100.0f * sqrt(3) - 200.0f},
		//{500.0f, -100.0f * sqrt(3)- 200.0f},
		//{550.0f, -50.0f * sqrt(3) - 200.0f},
		////{500.0f, -200.0f},
		////{400.0f, -200.0f},
		//{350.0f, -50.0f * sqrt(3)- 200.0f}
	};
	b2Vec2 gravity(0.0f, -10.0f);
	b2World world(gravity);

	b2BodyDef groundBodyDef;
	groundBodyDef.position.Set(700.0f, -600.0f);

	b2Body* groundBody = world.CreateBody(&groundBodyDef);
	b2PolygonShape groundBox;
	groundBox.SetAsBox(800.0f, 1.0f);
	groundBody->CreateFixture(&groundBox, 0.0f);

	GR::DynamicObject obje(world, deltaTime, vertices3, "cos.txt");
	GR::DynamicObject obj(world, deltaTime, vertices, "cpingwin.png");
	GR::DynamicObject ob(world, deltaTime, vertices2, "cpingwin.png");
	ob.attachText(tekst);
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
	obj.setRotationSpeed(.5f);
	while (!wormsWindow.isDone()) {
		deltaTime = ck.restart().asSeconds();
		wormsWindow.setBackGroundColor(200, 200, 200);
		obje.update();
		obj.update();
		ob.update();
		//obj.rotate(deltaTime);
		wormsWindow.update();							// 10 is a random value for now
		//std::cout << wormsWindow.getMouseWorldCoords().x << ' ' << wormsWindow.getMouseWorldCoords().y << std::endl;
		wormsWindow.draw(obje);
		wormsWindow.draw(obj);
		wormsWindow.draw(ob);
		wormsWindow.endDraw();
		world.Step(deltaTime, 6, 2);

	}
	return 0;
}