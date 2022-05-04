#include "window.h"
#include "game_object.h"

#include <iostream>

GR::Window::Window(float& deltaTime, const std::string& title)
	: windowTitle(title), windowSize({resolutions[0].first, resolutions[0].second}), resolutionPointer(0), deltaTime(deltaTime) {
	setup(title, 0);
}

GR::Window::~Window() {
	destroy();
}

void GR::Window::setup(const std::string& title, int resPtr, unsigned int MSAlevel) {
	windowTitle = title;
	windowSize = {resolutions[resPtr].first, resolutions[resPtr].second};
	view = sf::View(0.5f * sf::Vector2f(windowSize.x, windowSize.y), sf::Vector2f(windowSize.x, windowSize.y));
	mZoom = 1.0f;
	isWinDone = false;
	isWinFullscreen = false;
	settings.antialiasingLevel = MSAlevel;
	create();
}

void GR::Window::create() {
	view = sf::View(0.5f * sf::Vector2f(windowSize.x, windowSize.y), sf::Vector2f(windowSize.x, windowSize.y));
	auto style = (isWinFullscreen ? sf::Style::Fullscreen : sf::Style::Default);
	window.create({ windowSize.x, windowSize.y, 32 }, windowTitle, style, settings);
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
		case sf::Event::MouseWheelMoved:
			std::cout << mZoom << std::endl;
			std::cout << view.getSize().x << ' ' << view.getSize().y << std::endl;
			zoom(mouseWheelSpeed * deltaTime * event.mouseWheel.delta);
			break;

		}
	}
	mouseButtonBindings.listenAndUseAllMouseButtons(*this);
}

void GR::Window::addKeyBinding(sf::Keyboard::Key keyCode, void (GR::Window::*pointer)()) {
	keyBindings.addBinding(keyCode, pointer);
}

//void GR::Window::addMouseButtonBinding(sf::Mouse::Button button, void (GR::Window::* pointer)()) {
//	mouseButtonBindings.addBinding(button, pointer);
//}

void GR::Window::removeKeyBinding(sf::Keyboard::Key keyCode) {
	keyBindings.removeBinding(keyCode);
}

//void GR::Window::removeMouseButtonKeyBinding(sf::Mouse::Button button) {
//	mouseButtonBindings.removeBinding(button);
//}

void GR::Window::setFramesPerSecond(unsigned int fps) {
	window.setFramerateLimit(fps);
}

void GR::Window::setBackGroundColor(unsigned char r, unsigned char g, unsigned char b, unsigned char a) {
	window.clear({r, g, b, a});
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

void GR::Window::beginDraw(unsigned char r, unsigned char g, unsigned char b, unsigned char a) {
	window.clear({r, g, b, a});
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

void GR::Window::draw(GR::GameObject& drawable) {
	window.draw(drawable.getShape());
}

void GR::Window::setMultisamplingLevel(unsigned int level) {
	settings.antialiasingLevel = level;
	destroy();
	create();
}

void GR::Window::setView(float x, float y, float w, float h) {
	view = sf::View(sf::FloatRect(x, y, w, h));
	window.setView(view);
}

void GR::Window::zoom(float scale) {
	mZoom = mZoom * (1.0f - scale);
	view.zoom(1.0f - scale);
	window.setView(view);
}

void GR::Window::setZoomSpeed(float speed) {
	mouseWheelSpeed = speed;
}