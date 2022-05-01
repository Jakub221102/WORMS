#include <iostream>
 #include "SFML/Graphics.hpp"

#include "window.h"
#include "cyclic_singly_linked_list.h"

int main() {
	//sf::RenderWindow window(sf::VideoMode(800, 800), "Test");
	//sf::Event e;
	GR::Window wormsWindow;
	CyclicSinglyLinkedList<int> list;
	std::cout << list;
	list.addToTail(20);
	list.addToTail(10);
	list.addToTail(30);
	list.addToTail(40);
	list.remove(10);
	list.remove(30);
	std::cout << list << std::endl;
	list.remove(40);	
	list.remove(20);
	list.remove(50);
	std::cout << list;
	wormsWindow.addKeyBinding(sf::Keyboard::Key::A, &GR::Window::toggleFullScreen);
	wormsWindow.addKeyBinding(sf::Keyboard::Key::Escape, &GR::Window::close);
	wormsWindow.addKeyBinding(sf::Keyboard::Key::W, &GR::Window::upscaleResolution);
	wormsWindow.addKeyBinding(sf::Keyboard::Key::S, &GR::Window::downscaleResolution);
	//wormsWindow.removeKeyBinding(sf::Keyboard::Key::A);
	sf::RectangleShape shape(sf::Vector2f(200.0f, 200.0f));
	shape.setPosition(sf::Vector2f(200.0f, 200.0f));
	sf::Texture tekstura;
	tekstura.loadFromFile("brick.jpg");
	sf::Time t;
	sf::Sprite obrazek;
	obrazek.setTexture(tekstura);
	float time = 0.0f;
	sf::Clock ck;
	ck.restart();
	shape.setTexture(&tekstura);
	
	while (!wormsWindow.isDone()) {
		float time = ck.restart().asSeconds();
		wormsWindow.update(10);
		//obrazek.setOrigin(100, 80);				
		//obrazek.setPosition(100, 80);
		shape.rotate(2.0f * time);
		wormsWindow.beginDraw();
		wormsWindow.draw(shape);
		wormsWindow.endDraw();
	}
	return 0;
}