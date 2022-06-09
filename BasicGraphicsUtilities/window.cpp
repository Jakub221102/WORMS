#pragma once
#include "window.h"

GR::Window::Window(float& deltaTime, const std::string& title)
	: windowTitle(title), confines({ 0.0f, 0.0f }, {1000.0f, 1000.0f}), resolutionPointer(0), deltaTime(deltaTime) {
	setup(title, 0);
}

GR::Window::~Window() {
	destroy();
}

void GR::Window::setup(const std::string& title, int resPtr, unsigned int MSAlevel) {
	windowTitle = title;
	mouseWheelSpeed = 1.0f;
	windowSize = {resolutions[resPtr].first, resolutions[resPtr].second};
	mousePosition = sf::Vector2i();
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
	setViewBorder(confines.left, confines.top, confines.width, confines.height);
}

void GR::Window::destroy() {
	window.close();
}

void GR::Window::update() {
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
			zoom(mouseWheelSpeed * deltaTime * event.mouseWheel.delta);
			break;
		case sf::Event::MouseMoved:
			mousePosition = sf::Vector2i(event.mouseMove.x, event.mouseMove.y);
		}
	}
	//mouseButtonBindings.listenAndUseAllMouseButtons(*this);
}

void GR::Window::addKeyBinding(sf::Keyboard::Key keyCode, void (GR::Window::*pointer)()) {
	keyBindings.addBinding(keyCode, pointer);
}

void GR::Window::removeKeyBinding(sf::Keyboard::Key keyCode) {
	keyBindings.removeBinding(keyCode);
}


void GR::Window::setKeyArguments(sf::Keyboard::Key keyCode, const std::vector<float>& args) {
	keyBindings.setArguments(keyCode, args);
}

void GR::Window::setFramesPerSecond(unsigned int fps) {
	window.setFramerateLimit(fps);
}

void GR::Window::setBackGroundColor(unsigned char r, unsigned char g, unsigned char b, unsigned char a) {
	window.clear({r, g, b, a});
}

sf::Vector2f GR::Window::getMouseWorldCoords() const {
	return window.mapPixelToCoords(mousePosition);
}

void GR::Window::toggleFullScreen() { 
	isWinFullscreen = !isWinFullscreen;
	isWinFullscreen ? windowSize = { resolutions[0].first,
		resolutions[0].second } :
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

void GR::Window::draw(GR::StaticObject& drawable) {
	window.draw(drawable.getShape());
	if (drawable.getString() != "")
		window.draw(drawable.getText());
}

void GR::Window::draw(Worm& worm) {
	draw(static_cast<GR::StaticObject&>(worm));
	if(worm.active())
		draw(worm.getCurrentWeapon());
	if (worm.hasBullet())
		draw(worm.drawableBullet());
}


//void GR::Window::draw(Worm worm) {
//
//}

void GR::Window::setMultisamplingLevel(unsigned int level) {
	settings.antialiasingLevel = level;
	destroy();
	create();
}

bool GR::Window::setView(float x, float y, float w, float h) {
	if (confines.left > x || confines.top > y || w + x > confines.left + confines.width || y + h > confines.top + confines.height)
		return false;
	view = sf::View(sf::FloatRect(x, y, w, h));
	window.setView(view);
	return true;
}

void GR::Window::zoom(float scale) {
	sf::View temp = view;
	temp.zoom(1.0f - scale);
	auto rect = viewRectangle(temp);
	if (!setView(rect.left, rect.top, rect.width, rect.height)) return;
	mZoom = mZoom * (1.0f - scale);
}

void GR::Window::setZoomSpeed(float speed) {
	mouseWheelSpeed = speed;
}

sf::FloatRect GR::Window::viewRectangle(sf::View view) const {
	sf::Vector2f size = view.getSize();
	sf::Vector2f center = view.getCenter();
	sf::Vector2f leftTop = { center.x - size.x / 2.0f, center.y - size.y / 2.0f };
	return sf::FloatRect(leftTop, size);
}

void GR::Window::setViewBorder(float left, float top, float width, float height) {
	confines = sf::FloatRect(left, top, width, height);
	sf::FloatRect vRect = viewRectangle(view);
	if(left > vRect.left || top > vRect.top || vRect.width + vRect.left > left + width || vRect.top + vRect.height > top + height)
		setView(left, top, width, height);
	vRect = viewRectangle(view);
}

float GR::Window::getZoom() const {
	return mZoom;
}

sf::FloatRect GR::Window::getViewRect() const {
	return viewRectangle(view);
}

