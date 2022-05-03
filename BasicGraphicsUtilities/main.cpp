#include <iostream>
 #include "SFML/Graphics.hpp"

#include "window.h"
#include "cyclic_singly_linked_list.h"
#include "animated_object.h"
//#include "animated_object.h"

float deltaTime;

int main() {
	//sf::RenderWindow window(sf::VideoMode(800, 800), "Test");
	//sf::Event e;
	GR::Window wormsWindow;
	wormsWindow.addKeyBinding(sf::Keyboard::Key::L, &GR::Window::toggleFullScreen);
	wormsWindow.addKeyBinding(sf::Keyboard::Key::Escape, &GR::Window::close);
	wormsWindow.addKeyBinding(sf::Keyboard::Key::O, &GR::Window::upscaleResolution);
	wormsWindow.addKeyBinding(sf::Keyboard::Key::P, &GR::Window::downscaleResolution);

	//wormsWindow.removeKeyBinding(sf::Keyboard::Key::A);
	std::vector<std::pair<float, float>> vertices{
		{300.0f, 300.0f},
		{700.0f, 300.0f},
		{700.0f, 700.0f},
		{300.0f, 700.0f}
	};
	GR::GameObject rect(deltaTime, vertices, "rakieta.png");
	GR::AnimatedObject obj(deltaTime, vertices, "robole.png", 4, 1.0f);
	sf::Time t;
	sf::Clock ck;
	ck.restart();
	//rect.translate(800.0f, 100.0f);
	while (!wormsWindow.isDone()) {
		deltaTime = ck.restart().asSeconds();
		
		wormsWindow.update(10);
		wormsWindow.setBackGroundColor(200, 200, 200);
		obj.update();
		//obrazek.setOrigin(100, 80);				
		//obrazek.setPosition(100, 80);
		//wormsWindow.beginDraw();
		wormsWindow.draw(obj);
		wormsWindow.endDraw();
	}
	return 0;
}