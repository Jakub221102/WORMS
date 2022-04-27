#include "window.h"

#include <iostream>

GR::Window::Window(const std::string& title)
	: windowTitle(title), windowSize({resolutions[0].first, resolutions[0].second}), resolutionPointer(0) {
	setup(title, 0);
}

GR::Window::~Window() {
	destroy();
}

void GR::Window::setup(const std::string& title, int resPtr) {
	windowTitle = title;
	windowSize = {resolutions[resPtr].first, resolutions[resPtr].second};
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

void GR::Window::update(float time) {
	sf::Event event;
	
	while (window.pollEvent(event)) {
		switch (event.type) {
		case sf::Event::Closed:
			isWinDone = true;
			break;
		case sf::Event::KeyPressed:
			keyBindings.use(*this, event.key.code);
			break;
		}
	}
}

void GR::Window::addKeyBinding(sf::Keyboard::Key keyCode, void (GR::Window::*pointer)()) {
	keyBindings.addKeyBinding(keyCode, pointer);
}

void GR::Window::removeKeyBinding(sf::Keyboard::Key keyCode) {
	keyBindings.removeKeyBinding(keyCode);
}

void GR::Window::setFramesPerSecond(unsigned int fps) {
	window.setFramerateLimit(fps);
}

void GR::Window::toggleFullScreen() { 
	isWinFullscreen = !isWinFullscreen;
	isWinFullscreen ? windowSize = { 1920, 1080 } : 
		windowSize = { resolutions[resolutionPointer].first,
		resolutions[resolutionPointer].second } ;
	destroy();
	create();
}

void GR::Window::upscaleResolution() {
	if (!isWinFullscreen && resolutionPointer > 0) {
		--resolutionPointer;
		windowSize = { resolutions[resolutionPointer].first,
			resolutions[resolutionPointer].second };
		destroy();
		create();
	}
}

void GR::Window::downscaleResolution() {
	if (!isWinFullscreen && resolutionPointer < resolutions.size() - 1) {
		++resolutionPointer;
		windowSize = { resolutions[resolutionPointer].first,
			resolutions[resolutionPointer].second };
		destroy();
		create();
	}
}

void GR::Window::close() {
	isWinDone = true;
	window.close();
}

void GR::Window::beginDraw() {
	window.clear(sf::Color::Black);
}

void GR::Window::endDraw() {
	window.display();
}

bool GR::Window::isDone() const {
	return isWinDone;
}

bool GR::Window::isFullscreen() const {
	return isWinFullscreen;
}

sf::Vector2u GR::Window::getWindowSize() const {
	return windowSize;
}

void GR::Window::draw(sf::Drawable& drawable) {
	window.draw(drawable);
}