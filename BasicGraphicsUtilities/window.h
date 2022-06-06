#pragma once
#include "SFML/Graphics.hpp"
#include "input_manager.h"
//#include "worm.h"
#include "static_game_object.h"
#include "worm.h"
#include <iostream>

#include <string>
#include <unordered_map>
#include <vector>

//class Worm;

namespace GR {
	const std::vector<std::pair<unsigned int, unsigned int>> resolutions = {
		{1920, 1080},
		{1440, 1080},
		{1280, 1080},
		{1280, 720},
		{720, 576},
		{704, 576},
		{544, 576},
		{480, 576}
	};
	class Window {
		void setup(const std::string& title, int resolutionPointer, unsigned int MSAlevel = 16);
		void destroy();
		void create();
	protected:
		sf::RenderWindow window;
		sf::ContextSettings settings;
		sf::Vector2u windowSize;
		std::string windowTitle;
		sf::Vector2f resolutionScale;
		sf::Vector2i mousePosition;
		sf::FloatRect confines;
		sf::View view;
		int resolutionPointer;
		bool isWinDone;
		bool isWinFullscreen;
		const float& deltaTime;
		float mouseWheelSpeed;
		float mZoom;
		GR::RealTimeMouseManager<GR::Window, sf::Mouse::Button> mouseButtonBindings;
		EventManager<GR::Window, sf::Keyboard::Key> keyBindings;
	public:
		Window(float& deltaTime, const std::string& title = "Window");
		~Window();

		void addKeyBinding(sf::Keyboard::Key keyCode, void (GR::Window::*pointer)());
		void removeKeyBinding(sf::Keyboard::Key keyCode);
		void setKeyArguments(sf::Keyboard::Key keyCode, const std::vector<float>& args);

		void beginDraw(unsigned char r=0, unsigned char g=0, unsigned char b=0, unsigned char a = 255);
		void endDraw();
		void update();
		void setFramesPerSecond(unsigned int fps);

		bool isDone() const;
		bool isFullscreen() const;
		sf::Vector2u getWindowSize() const;
		void setBackGroundColor(unsigned char r, unsigned char g, unsigned char b, unsigned char a=255);
		sf::Vector2f getMouseWorldCoords() const;

		void draw(GR::StaticObject& drawable);
		void draw(Worm& worm);
		//void draw(const Worm& worm);
		sf::FloatRect viewRectangle(sf::View view) const;
		sf::FloatRect getViewRect() const;
		void toggleFullScreen();
		void close();
		void upscaleResolution();
		void downscaleResolution();
		void setMultisamplingLevel(unsigned int level);
		bool setView(float x, float y, float w, float h);
		void zoom(float scale);
		float getZoom() const;
		void setZoomSpeed(float speed);
		void setViewBorder(float left, float top, float width, float height);
	};
}