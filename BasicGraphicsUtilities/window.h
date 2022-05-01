#pragma once
#include "SFML/Graphics.hpp"

#include "input_manager.h"

#include <string>
#include <unordered_map>
#include <vector>

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

		sf::RenderWindow window;
		sf::ContextSettings settings;
		sf::Vector2u windowSize;
		std::string windowTitle;
		int resolutionPointer;
		bool isWinDone;
		bool isWinFullscreen;
		//std::unordered_map<sf::Keyboard::Key, void (GR::Window::*)()> keyBindings;
		GR::EventManager<sf::Keyboard::Key, GR::Window> keyBindings;
	public:
		Window(const std::string& title = "Window");
		~Window();

		void addKeyBinding(sf::Keyboard::Key keyCode, void (GR::Window::*pointer)());
		void removeKeyBinding(sf::Keyboard::Key keyCode);

		void beginDraw();
		void endDraw();
		void update(float time);
		void setFramesPerSecond(unsigned int fps);

		bool isDone() const;
		bool isFullscreen() const;
		sf::Vector2u getWindowSize() const;

		void draw(sf::Drawable& drawable);

		// member functions to bind keys
		void toggleFullScreen();
		void close();
		void upscaleResolution();
		void downscaleResolution();
		void setMultisamplingLevel(unsigned int level);
	};
}