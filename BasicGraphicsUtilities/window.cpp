#include "window.h"

GR::Window::Window(const std::string& title, const sf::Vector2u& size)
	: windowTitle(title), windowSize(size) {
	setup(title, size);
}

GR::Window::~Window() {
	destroy();
}

void GR::Window::setup(const std::string& title, const sf::Vector2u& size) {
	windowTitle = title;
	windowSize = size;
	isWinDone = false;
	isWinFullscreen = false;
	create();
}

void GR::Window::create() {
	auto style = (isWinFullscreen ? sf::Style::Fullscreen : sf::Style::Default);
	window.create({ windowSize.x, windowSize.y, 32 }, windowTitle, style);
}

void GR::Window::destroy() {
	window.close();
}

void GR::Window::update() {
	sf::Event event;
	while (window.pollEvent(event)) {
		if (event.type == sf::Event::Closed) isWinDone = true;
		else if (event.type == sf::Event::KeyPressed) {
			if (event.key.code == sf::Keyboard::F5) toggleFullScreen();
		}
	}
}

void GR::Window::toggleFullScreen() {
	isWinFullscreen = !isWinFullscreen;
	destroy();
	create();
}

void GR::Window::beginDraw() {
	window.clear(sf::Color::Black);
}

void GR::Window::endDraw() {
	window.display();
}

bool GR::Window::isDone() {
	return isWinDone;
}

bool GR::Window::isFullscreen() {
	return isWinFullscreen;
}

sf::Vector2u GR::Window::getWindowSize() {
	return windowSize;
}

void GR::Window::draw(sf::Drawable& drawable) {
	window.draw(drawable);
}