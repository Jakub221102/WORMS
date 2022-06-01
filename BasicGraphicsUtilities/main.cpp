#pragma once
#include <iostream>

#include "SFML/Graphics.hpp"
#include "box2d.h"
#include "input_manager.h"

#include "window.h"
#include "static_animated_object.h"
#include "static_object_relative.h"
#include "dynamic_game_object.h"
#include "static_physical_object.h"
#include "worm.h"

float deltaTime;

int main() {
	GR::Window wormsWindow(deltaTime);
	GR::Text tekst("ala ma kota");
	tekst.setPosition(600.0f, 600.0f);
	tekst.setRelativeTranslation(-45.0f, -45.0f);
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
		{555.0f, 60.0f},
		{555.0f, 80.0f},
		{540.0f, 80.0f}
	};

	std::vector<std::pair<float, float>> terrain{
		{0.0f, 900.0f},
		{1000.0f, 900.0f},
		{1000.0f, 1000.0f},
		{0.0f, 1000.0f}
	};

	std::vector<std::pair<float, float>> terrain2{
		{1001.0f, 900.0f},
		{1500.0f, 900.0f},
		{1500.0f, 1000.0f},
		{1001.0f, 1000.0f}
	};


	std::vector<std::pair<float, float>> vertices3{
		{400.0f, 400.0f},
		{500.0f, 580.0f},
		{600.0f, 400.0f},
		{600.0f, 600.0f},
		{400.0f, 600.0f},

		/*{400.0f, -100.0f * sqrt(3) + 800.0f},
		{500.0f, -100.0f * sqrt(3) + 800.0f},
		{550.0f, -150.0f * sqrt(3) + 800.0f},
		{650.0f, -150.0f * sqrt(3) + 800.0f},
		{700.0f, -200.0f * sqrt(3) + 800.0f},
		{800.0f, -200.0f * sqrt(3) + 800.0f},
		{850.0f, -150.0f * sqrt(3) + 800.0f},*/
		//{850.0f, -100.0f * sqrt(3) + 800.0f},
		{850.0f, 800.0f},
		{400.0f, 800.0f},
		/*{350.0f, -50.0f * sqrt(3) + 900.0f},*/
		
		
		//{400.0f, -100.0f * sqrt(3) - 200.0f},
		//{500.0f, -100.0f * sqrt(3)- 200.0f},
		//{550.0f, -50.0f * sqrt(3) - 200.0f},
		////{500.0f, -200.0f},
		////{400.0f, -200.0f},
		//{350.0f, -50.0f * sqrt(3)- 200.0f}
	};
	b2Vec2 gravity(0.0f, -10.0f);
	b2World world(gravity);

	/*b2BodyDef groundBodyDef;
	groundBodyDef.position.Set(700.0f, -600.0f);

	b2Body* groundBody = world.CreateBody(&groundBodyDef);
	b2PolygonShape groundBox;
	groundBox.SetAsBox(800.0f, 1.0f);
	groundBody->CreateFixture(&groundBox, 0.0f);*/

	Worm obj(world, deltaTime, vertices2, "sovleftmarch.png");
	/*Worm obje(world, deltaTime, vertices3, "sov");*/
	GR::StaticPhysicalObject mTerrain(world, deltaTime, terrain, "dsaw");
	GR::StaticPhysicalObject m2Terrain(world, deltaTime, terrain2, "dsaw");
	obj.addAnimation("march", "sovleftmarch.png", 4, 3.0f);
	obj.setCurrentAnimation("march");
	obj.addKeyBinding(sf::Keyboard::Space, &Worm::jump, InputType::REALTIME);
	obj.setKeyArguments(sf::Keyboard::Space, {0.0f, 25.0f}, InputType::REALTIME); // pass velocity to jump method
	obj.addKeyBinding(sf::Keyboard::Right, &Worm::move_right, InputType::REALTIME);
	obj.setKeyArguments(sf::Keyboard::Right, {25.0f, -10.0f }, InputType::REALTIME); // pass velocity to move method
	obj.addKeyBinding(sf::Keyboard::Left, &Worm::move_left, InputType::REALTIME);
	obj.setKeyArguments(sf::Keyboard::Left, {-25.0f, -10.0f }, InputType::REALTIME); // pass velocity to move method
	obj.addKeyBinding(sf::Keyboard::Down, &Worm::move_down, InputType::REALTIME);
	obj.setKeyArguments(sf::Keyboard::Down, { 0.0f, -50.0f }, InputType::REALTIME); // pass velocity to move method
	GR::DynamicObject obje(world, deltaTime, vertices3, "cpingwin.png");
	/*GR::DynamicObject ob(world, deltaTime, vertices2, "cpingwin.png");*/
	//GR::RelativeStaticObject git(deltaTime, vertices3, "raki");
	//git.attachViewAndZoom(wormsWindow);
	//git.setRelativeVector(50.0f, 50.0f);
	/*obje.attachText(tekst);*/
	//obj.putVelocity(-10000000.0f, -10.0f);
	obj.addAnimation("IDLE", "pingwin.png", 4, 4.0f);
	obj.addAnimation("WORM", "sovleftmarch.png", 4, 3.0f);
	obj.setCurrentAnimation("WORM");
	sf::Clock ck;
	ck.restart();
	//obj.translate({ 500.0f, 0.0f });
	//obj.setPosition({ 0.0f, 0.0f });
	float global = 0.0f;
	//obj.setScale({ 1.5f, 1.5f });
	//obj.setRotationSpeed(.5f);
	while (!wormsWindow.isDone()) {
		deltaTime = ck.restart().asSeconds();
		wormsWindow.setBackGroundColor(200, 200, 200);
		/*obje.updateNoControl();*/
		obj.update();
		obje.update();
		wormsWindow.update();							// 10 is a random value for now
		//git.update();									// needs to be called after window.update()
		//obj.rotate(deltaTime);
		//std::cout << wormsWindow.getMouseWorldCoords().x << ' ' << wormsWindow.getMouseWorldCoords().y << std::endl;
		wormsWindow.draw(obje);
		wormsWindow.draw(obj);
		//wormsWindow.draw(ob);
		//wormsWindow.draw(git);
		wormsWindow.draw(mTerrain);
		wormsWindow.draw(m2Terrain);
		wormsWindow.endDraw();
		world.Step(deltaTime, 6, 2);

	}
	return 0;
}