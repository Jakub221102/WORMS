#pragma once
#include <iostream>

#include "SFML/Graphics.hpp"
#include "box2d.h"
#include "input_manager.h"

#include "window.h"
#include "static_animated_object.h"
#include "dynamic_game_object.h"

float deltaTime;

int main() {
	GR::Window wormsWindow(deltaTime);
	//wormsWindow.setFramesPerSecond(60);
	wormsWindow.setKeyArguments(sf::Keyboard::A, { 10.0f });
	wormsWindow.setViewBorder(0, 0.0f, 1920.0f, 1080.0f);
	wormsWindow.setView(960.0f, 540.0f, 960.0f, 540.0f); // view does not fit in viewBorder so view is set to viewBorder by default
	wormsWindow.setZoomSpeed(200.0f);

	std::vector<std::pair<float, float>> vertices_background{
		{960.0f, 540.0f},
		{1920.0f, 540.0f},
		{1920.0f, 1080.0f},
		{960.0f, 1080.0f}
	};

	std::vector<std::pair<float, float>> vertices_worm1s{
		{1587.0f, 844.0f},
		{1602.0f, 844.0f},
		{1602.0f, 864.0f},
		{1587.0f, 864.0f}
	};

	std::vector<std::pair<float, float>> vertices_worm2s{
		{1365.0f, 770.0f},
		{1380.0f, 770.0f},
		{1380.0f, 790.0f},
		{1365.0f, 790.0f}
	};

	std::vector<std::pair<float, float>> vertices_worm3s{
		{1537.0f, 770.0f},
		{1552.0f, 770.0f},
		{1552.0f, 790.0f},
		{1537.0f, 790.0f}
	};

	std::vector<std::pair<float, float>> vertices_worm1g{
		{1731.0f, 748.0f},
		{1746.0f, 748.0f},
		{1746.0f, 768.0f},
		{1731.0f, 768.0f}
	};

	std::vector<std::pair<float, float>> vertices_worm2g{
		{1777.0f, 898.0f},
		{1792.0f, 898.0f},
		{1792.0f, 918.0f},
		{1777.0f, 918.0f}
	};

	std::vector<std::pair<float, float>> vertices_worm3g{
		{1544.0f, 1003.0f},
		{1559.0f, 1003.0f},
		{1559.0f, 1023.0f},
		{1544.0f, 1023.0f}
	};

	std::vector<std::pair<float, float>> vertices_worm1b{
		{1275.0f, 1003.0f},
		{1290.0f, 1003.0f},
		{1290.0f, 1023.0f},
		{1275.0f, 1023.0f}
	};

	std::vector<std::pair<float, float>> vertices_worm2b{
		{1367.0f, 898.0f},
		{1382.0f, 898.0f},
		{1382.0f, 918.0f},
		{1367.0f, 918.0f}
	};

	std::vector<std::pair<float, float>> vertices_worm3b{
		{1136.0f, 925.0f},
		{1151.0f, 925.0f},
		{1151.0f, 945.0f},
		{1136.0f, 945.0f}
	};

	std::vector<std::pair<float, float>> vertices_worm1p{
		{1095.0f, 816.0f},
		{1110.0f, 816.0f},
		{1110.0f, 836.0f},
		{1095.0f, 836.0f}
	};

	std::vector<std::pair<float, float>> vertices_worm2p{
		{1235.0f, 842.0f},
		{1250.0f, 842.0f},
		{1250.0f, 862.0f},
		{1235.0f, 862.0f}
	};
	
	std::vector<std::pair<float, float>> vertices_worm3p{
		{1195.0f, 763.0f},
		{1210.0f, 763.0f},
		{1210.0f, 783.0f},
		{1195.0f, 783.0f}
	};

	b2Vec2 gravity(0.0f, -10.0f);
	b2World world(gravity);

	b2BodyDef groundBodyDef;
	groundBodyDef.position.Set(700.0f, -600.0f);

	b2Body* groundBody = world.CreateBody(&groundBodyDef);
	b2PolygonShape groundBox;
	groundBox.SetAsBox(800.0f, 1.0f);
	groundBody->CreateFixture(&groundBox, 0.0f);

	GR::StaticObject sky(deltaTime, vertices_background, "niebo.png");
	GR::StaticObject ground(deltaTime, vertices_background, "ziemia.png");
	GR::StaticObject water(deltaTime, vertices_background, "woda.png");

	GR::StaticAnimatedObject worm1s(deltaTime, vertices_worm1s, "sovfront.png");
	GR::StaticAnimatedObject worm2s(deltaTime, vertices_worm2s, "sovfront.png");
	GR::StaticAnimatedObject worm3s(deltaTime, vertices_worm3s, "sovfront.png");

	GR::StaticAnimatedObject worm1g(deltaTime, vertices_worm1g, "tzegerfront.png");
	GR::StaticAnimatedObject worm2g(deltaTime, vertices_worm2g, "tzegerfront.png");
	GR::StaticAnimatedObject worm3g(deltaTime, vertices_worm3g, "tzegerfront.png");

	GR::StaticAnimatedObject worm1b(deltaTime, vertices_worm1b, "britfront.png");
	GR::StaticAnimatedObject worm2b(deltaTime, vertices_worm2b, "britfront.png");
	GR::StaticAnimatedObject worm3b(deltaTime, vertices_worm3b, "britfront.png");

	GR::StaticAnimatedObject worm1p(deltaTime, vertices_worm1p, "polfront.png");
	GR::StaticAnimatedObject worm2p(deltaTime, vertices_worm2p, "polfront.png");
	GR::StaticAnimatedObject worm3p(deltaTime, vertices_worm3p, "polfront.png");

	worm1s.addAnimation("WORM1S", "sovfront.png", 3, 4.0f);
	worm1s.setCurrentAnimation("WORM1S");
	worm2s.addAnimation("WORM2S", "sovfront.png", 3, 4.0f);
	worm2s.setCurrentAnimation("WORM2S");
	worm3s.addAnimation("WORM3S", "sovfront.png", 3, 4.0f);
	worm3s.setCurrentAnimation("WORM3S");

	worm1g.addAnimation("WORM1G", "tzegerfront.png", 3, 4.0f);
	worm1g.setCurrentAnimation("WORM1G");
	worm2g.addAnimation("WORM2G", "tzegerfront.png", 3, 4.0f);
	worm2g.setCurrentAnimation("WORM2G");
	worm3g.addAnimation("WORM3G", "tzegerfront.png", 3, 4.0f);
	worm3g.setCurrentAnimation("WORM3G");

	worm1b.addAnimation("WORM1B", "britfront.png", 3, 4.0f);
	worm1b.setCurrentAnimation("WORM1B");
	worm2b.addAnimation("WORM2B", "britfront.png", 3, 4.0f);
	worm2b.setCurrentAnimation("WORM2B");
	worm3b.addAnimation("WORM3B", "britfront.png", 3, 4.0f);
	worm3b.setCurrentAnimation("WORM3B");

	worm1p.addAnimation("WORM1P", "polfront.png", 3, 4.0f);
	worm1p.setCurrentAnimation("WORM1P");
	worm2p.addAnimation("WORM2P", "polfront.png", 3, 4.0f);
	worm2p.setCurrentAnimation("WORM2P");
	worm3p.addAnimation("WORM3P", "polfront.png", 3, 4.0f);
	worm3p.setCurrentAnimation("WORM3P");

	sf::Clock ck;
	ck.restart();
	//sky.translate({ 500.0f, 0.0f });
	//sky.setPosition({ 0.0f, 0.0f });
	float global = 0.0f;
	while (!wormsWindow.isDone()) {
		deltaTime = ck.restart().asSeconds();
		wormsWindow.setBackGroundColor(200, 200, 200);

		worm1s.update();
		worm2s.update();
		worm3s.update();
		worm1g.update();
		worm2g.update();
		worm3g.update();
		worm1b.update();
		worm2b.update();
		worm3b.update();
		worm1p.update();
		worm2p.update();
		worm3p.update();

		//obj.rotate(deltaTime);
		wormsWindow.update();							// 10 is a random value for now
		std::cout << wormsWindow.getMouseWorldCoords().x << ' ' << wormsWindow.getMouseWorldCoords().y << std::endl;

		wormsWindow.draw(sky);
		wormsWindow.draw(ground);
		wormsWindow.draw(water);
		wormsWindow.draw(worm1s);
		wormsWindow.draw(worm2s);
		wormsWindow.draw(worm3s);
		wormsWindow.draw(worm1g);
		wormsWindow.draw(worm2g);
		wormsWindow.draw(worm3g);
		wormsWindow.draw(worm1b);
		wormsWindow.draw(worm2b);
		wormsWindow.draw(worm3b);
		wormsWindow.draw(worm1p);
		wormsWindow.draw(worm2p);
		wormsWindow.draw(worm3p);

		wormsWindow.endDraw();
		world.Step(deltaTime, 6, 2);
	}
	return 0;
}
