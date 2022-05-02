#include <iostream>
 #include "SFML/Graphics.hpp"

#include "window.h"
#include "cyclic_singly_linked_list.h"

int main() {
	//sf::RenderWindow window(sf::VideoMode(800, 800), "Test");
	//sf::Event e;
	GR::Window wormsWindow;
	wormsWindow.addKeyBinding(sf::Keyboard::Key::A, &GR::Window::toggleFullScreen);
	wormsWindow.addKeyBinding(sf::Keyboard::Key::Escape, &GR::Window::close);
	wormsWindow.addKeyBinding(sf::Keyboard::Key::W, &GR::Window::upscaleResolution);
	wormsWindow.addKeyBinding(sf::Keyboard::Key::S, &GR::Window::downscaleResolution);

	//wormsWindow.removeKeyBinding(sf::Keyboard::Key::A);
	std::vector<std::pair<float, float>> vertices{
		{300.0f, 300.0f},
		{400.0f, 300.0f},
		{400.0f, 500.0f},
		{300.0f, 500.0f}
	};
	GR::GameObject rect(vertices, "rakieta.png", 10.0f, 10.0f);
	sf::Time t;
	float time = 0.0f;
	sf::Clock ck;
	ck.restart();
	rect.translate(800.0f, 100.0f);
	while (!wormsWindow.isDone()) {
		float time = ck.restart().asSeconds();
		wormsWindow.update(10);
		wormsWindow.setBackGroundColor(25, 0, 0);
		//obrazek.setOrigin(100, 80);				
		//obrazek.setPosition(100, 80);
		rect.rotate(time * 2.0f);
		//wormsWindow.beginDraw();
		wormsWindow.draw(rect);
		wormsWindow.endDraw();
	}
	return 0;
}