#include <string>
#include <iostream>
#include <vector>
#include <chrono>
#include <thread>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include "objects.h"

using std::string;
using std::cout;
using std::cin;
using std::endl;

float deltaTime;


int main()
{
	b2Vec2 gravity(0.0f, -10.0f);
	b2World world(gravity);

	b2BodyDef groundBodyDef;
	groundBodyDef.position.Set(0.0f, -10.0f);

	b2Body* groundBody = world.CreateBody(&groundBodyDef);
	b2PolygonShape groundBox;
	groundBox.SetAsBox(100.0f, 10.0f);
	groundBody->CreateFixture(&groundBox, 0.0f);

	b2Vec2* v = new b2Vec2[4];
	v[0].Set(-2.0f, 2.0f);
	v[1].Set(2.0f, 2.0f);
	v[2].Set(2.0f, -2.0f);
	v[3].Set(-2.0f, -2.0f);
	std::vector<Polygon*> boxes;
	Polygon* r = new Polygon(world, 10, 10, v, 4);
	b2Vec2 v1(0.0f, 200.0f);
	//cout<<r->body->GetMass()<<endl;
	boxes.push_back(r);
	



	int input = 1;

	while (input!=0)
	{
		for (int i = 0; i < input; ++i)
		{
			world.Step(1.0f / 30.0f, 6, 2);
		}
		int a = 0;
		for (auto i : boxes)
		{
			r->body->ApplyForceToCenter(v1, true);
			b2Vec2 pos = i->getPosition();
			float angle = i->getAngle();
			cout << "Obj: " << a <<endl;
			cout << "x: " << pos.x << " y: " << pos.y << " angle: " << angle << endl;
			++a;
		}
		cin>>input;
	}


	return 0;
}
