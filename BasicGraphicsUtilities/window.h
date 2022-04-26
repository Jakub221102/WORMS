#pragma once
#include "SFML/Graphics.hpp"

#include <string>

namespace GR {
	class Window {
		void setup(const std::string& title, const sf::Vector2u& size);
		void destroy();
		void create();

		sf::RenderWindow window;
		sf::Vector2u windowSize;
		std::string windowTitle;
		bool isWinDone;
		bool isWinFullscreen;
	public:
		Window(const std::string& title = "Window", const sf::Vector2u& size = {1920, 1080});
		~Window();

		void beginDraw();
		void endDraw();
		void update();

		bool isDone();
		bool isFullscreen();
		sf::Vector2u getWindowSize();

		void toggleFullScreen();
		void draw(sf::Drawable& drawable);
	};
}