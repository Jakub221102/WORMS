#include <string>
#include <iostream>
#include <vector>
#include <chrono>
#include <thread>



//#include <SFML/Graphics.hpp>
//#include <SFML/System.hpp>
//#include <SFML/Audio.hpp>
//#include <SFML/Network.hpp>
//#include "./box2d_code/objects.h"
//
//#include "./BasicGraphicsUtilities/input_manager.h"
//#include "./BasicGraphicsUtilities/window.h"
//#include "./BasicGraphicsUtilities/static_animated_object.h"

#include "debug.h"


//float deltaTime;

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


	//terminalDraw(world, deltaTime);
	draw(world, deltaTime);
	return 0;
}