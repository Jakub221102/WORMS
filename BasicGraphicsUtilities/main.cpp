#include <iostream>
 #include "SFML/Graphics.hpp"

#include "window.h"
#include "animated_object.h"
//#include "animated_object.h"

float deltaTime;

int main() {
	//sf::RenderWindow window(sf::VideoMode(800, 800), "Test");
	//sf::Event e;
	GR::Window wormsWindow(deltaTime, {0.0, 0.0, 200.0f, 200.0f});
	wormsWindow.setZoomSpeed(4.0f);
	//wormsWindow.addMouseButtonBinding(sf::Mouse::Button::Left, &GR::Window::downscaleResolution);

	//wormsWindow.removeKeyBinding(sf::Keyboard::Key::A);
	std::vector<std::pair<float, float>> vertices{
		{300.0f, 300.0f},
		{700.0f, 300.0f},
		{700.0f, 700.0f},
		{300.0f, 700.0f}
	};
	GR::GameObject rect(deltaTime, vertices, "rakieta.png");
	GR::AnimatedObject obj(deltaTime, vertices, "pingwin.png");
	obj.addAnimation("IDLE", "pingwin.png", 4, 4.0f);
	obj.addAnimation("WORM", "robole.png", 4, 3.0f);
	obj.setCurrentAnimation("IDLE");
	rect.translate(700.0f, 0.0f);
	sf::Time t;
	sf::Clock ck;
	ck.restart();
	float global = 0.0f;
	//rect.translate(800.0f, 100.0f);
	//wormsWindow.setView(-500.0f, 0.0f, 2920.0f, 2080.0f);
	//wormsWindow.setView(0.0f, 0.0f, 1000.0f, 1080.0f);
	while (!wormsWindow.isDone()) {
		deltaTime = ck.restart().asSeconds();
		wormsWindow.setBackGroundColor(200, 200, 200);
		obj.update();
		//obrazek.setOrigin(100, 80);				
		//obrazek.setPosition(100, 80);
		//wormsWindow.beginDraw();
		wormsWindow.update(10);
		//std::cout << wormsWindow.getMouseWorldCoords().x << ' ' << wormsWindow.getMouseWorldCoords().y << std::endl;
		wormsWindow.draw(obj);
		wormsWindow.draw(rect);
		wormsWindow.endDraw();
	}
	return 0;
}