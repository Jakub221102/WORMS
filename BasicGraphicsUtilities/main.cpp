#pragma once
#include <iostream>

#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include "box2d/box2d.h"
#include "input_manager.h"

#include "window.h"
//#include "static_animated_object.h"
//#include "dynamic_game_object.h"
#include "dynamic_animated_object.h"
#include "sound_manager.h"

float deltaTime;

int main() {
	GR::Window wormsWindow(deltaTime);
	GR::SoundManager sm("sounds.txt");
	sm.setBackgroundMusic("Drakan.wav");	// Drakan.wav
	sm.playBackgroundMusic();
	//sm.playSound("Drakan");
	//muzyka.openFromFile("Drakan.wav");
	
	//muzyka.play();
	//wormsWindow.setFramesPerSecond(60);
	wormsWindow.setKeyArguments(sf::Keyboard::A, {10.0f});
	wormsWindow.setViewBorder(-1000.0f, -1000.0f, 2000.0f, 2000.0f);
	wormsWindow.setView(-1000.0f, -1000.0f, 2000.0f, 2000.0f); // view does not fit in viewBorder so view is set to viewBorder by default
	wormsWindow.setZoomSpeed(4.0f);

	std::vector<std::pair<float, float>> vertices {
		{300.0f, 300.0f},
		{700.0f, 300.0f},
		{700.0f, 700.0f},
		{300.0f, 700.0f}
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
	groundBodyDef.position.Set(0.0f, -300.0f);

	b2Body* groundBody = world.CreateBody(&groundBodyDef);
	b2PolygonShape groundBox;
	groundBox.SetAsBox(1000.0f, 10.0f);
	groundBody->CreateFixture(&groundBox, 0.0f);

	//GR::DynamicAnimatedObject object(world, deltaTime, vertices, "pingwin.png");
	//GR::DynamicObject obj(world, deltaTime, vertices, "pingwin.png");
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
	GR::DynamicAnimatedObject object(world, deltaTime, vertices, "pingwin.png");
	object.addAnimation("IDLE", "pingwin.png", 4, 4.0f);
	object.addAnimation("WORM", "robole.png", 4, 3.0f);
	object.setCurrentAnimation("IDLE");
	while (!wormsWindow.isDone()) {
		deltaTime = ck.restart().asSeconds();
		wormsWindow.setBackGroundColor(200, 200, 200);
		//obj.update();
		ob.update();
		object.update();
		//obj.rotate(deltaTime);
		wormsWindow.update();							// 10 is a random value for now
		std::cout << wormsWindow.getMouseWorldCoords().x << ' ' << wormsWindow.getMouseWorldCoords().y << std::endl;
		//std::cout << wormsWindow.getMouseWorldCoords().x << ' ' << wormsWindow.getMouseWorldCoords().y << std::endl;
		//wormsWindow.draw(obj);
		wormsWindow.draw(ob);
		wormsWindow.draw(object);
		wormsWindow.endDraw();
		world.Step(deltaTime, 6, 2);
	}
	return 0;
}