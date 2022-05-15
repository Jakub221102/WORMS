#include <string>
#include <iostream>
#include <vector>
#include <chrono>
#include <thread>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

#include "../BasicGraphicsUtilities/window.h"
#include "../BasicGraphicsUtilities/animated_object.h"
#include "objects.h"

using std::string;
using std::cout;
using std::endl;

float deltaTime;


int main() {
	cout << "Hello World" << endl;
	
	b2Vec2 gravity(0.0f, -10.0f);
	b2World world(gravity);

	b2BodyDef groundBodyDef;
	groundBodyDef.position.Set(0.0f, -10.0f);

	b2Body* groundBody = world.CreateBody(&groundBodyDef);
	b2PolygonShape groundBox;
	groundBox.SetAsBox(100.0f, 10.0f);
	groundBody->CreateFixture(&groundBox, 0.0f);
	
	
	GR::Window testWindow(deltaTime, { 0.0, 0.0, 200.0f, 200.0f });

	std::vector<std::pair<float, float>> vertices{
	{300.0f, 300.0f},
	{700.0f, 300.0f},
	{700.0f, 700.0f},
	{300.0f, 700.0f}
	};

	GR::GameObject rect(deltaTime, vertices, "rakieta.png");

	rect.translate(700.0f, 0.0f);
	rect.setRotation(10.0f);

	sf::Time t;
	sf::Clock ck;

	ck.restart();
	float global = 0.0f;

	b2Vec2* v = new b2Vec2[4];
	v[0].Set(-2.0f, 2.0f);
	v[1].Set(2.0f, 2.0f);
	v[2].Set(2.0f, -2.0f);
	v[3].Set(-2.0f, -2.0f);
	std::vector<Polygon*> boxes;
	Polygon* r = new Polygon(world, 10, 10, v, 4);
	boxes.push_back(r);

	std::vector<GR::GameObject*> rects;
	for (auto i : boxes)
	{
		std::vector<std::pair<float, float>> vert{
			{-200.0f, 200.0f},
			{200.0f, 200.0f},
			{200.0f, -200.0f},
			{-200.0f, -200.0f}
		};
		rects.push_back(new GR::GameObject(deltaTime, vert, ""));
	}

	while (!testWindow.isDone()) {
		deltaTime = ck.restart().asSeconds();
		testWindow.setBackGroundColor(200, 200, 200);
		world.Step(1.0f / 20.0f, 6, 2);
		//obrazek.setOrigin(100, 80);				
		//obrazek.setPosition(100, 80);
		//wormsWindow.beginDraw();
		testWindow.update(10);
		//std::cout << wormsWindow.getMouseWorldCoords().x << ' ' << wormsWindow.getMouseWorldCoords().y << std::endl;
		for (auto p : rects)
		{
			testWindow.draw(*p);
			b2Vec2 pos = r->getPosition();
			cout << pos.x << " x : y " << pos.y << endl;
			p->setPosition(pos.x*10, pos.y*10);
		}
		testWindow.endDraw();
		std::chrono::milliseconds timespan(40); // or whatever
		std::this_thread::sleep_for(timespan);
	}

	return 0;
}

