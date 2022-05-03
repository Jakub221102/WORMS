#include <iostream>
 #include "SFML/Graphics.hpp"

#include "window.h"
#include "cyclic_singly_linked_list.h"

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
		{400.0f, 300.0f},
		{400.0f, 500.0f},
		{300.0f, 500.0f}
	};
	GR::GameObject rect(deltaTime, vertices, "rakieta.png");
	rect.addKeyBinding(sf::Keyboard::Key::W, &GR::GameObject::moveUp);
	rect.addKeyBinding(sf::Keyboard::Key::A, &GR::GameObject::moveLeft);
	rect.addKeyBinding(sf::Keyboard::Key::S, &GR::GameObject::moveDown);
	rect.addKeyBinding(sf::Keyboard::Key::D, &GR::GameObject::moveRight);
	rect.addKeyBinding(sf::Keyboard::Key::Q, &GR::GameObject::rotateLeft);
	rect.addKeyBinding(sf::Keyboard::Key::E, &GR::GameObject::rotateRight);
	sf::Time t;
	sf::Clock ck;
	ck.restart();
	//rect.translate(800.0f, 100.0f);
	while (!wormsWindow.isDone()) {
		deltaTime = ck.restart().asSeconds();
		
		wormsWindow.update(10);
		rect.update();
		wormsWindow.setBackGroundColor(25, 0, 0);
		//obrazek.setOrigin(100, 80);				
		//obrazek.setPosition(100, 80);
		//wormsWindow.beginDraw();
		wormsWindow.draw(rect);
		wormsWindow.endDraw();
	}
	return 0;
}