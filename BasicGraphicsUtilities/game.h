#pragma once

#include "window.h"
#include "input_manager.h"
#include "world.h"
#include <list>

namespace GR {
	class Game {
		GR::Window window;
		GR::World world;
		EventManager<sf::Keyboard::Key, GR::Game> keyBindings;
		//std::lis
		sf::Clock clock;
		sf::Time elapsed;
	public:
		Game();
		~Game();

		void handleInput();
		void update(float time);
		void render();

		sf::Time getElapsed();
		float getElapsedSeconds();
		void restartClock();

		GR::Window& getWindow();

	};
}