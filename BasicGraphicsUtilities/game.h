#pragma once

#include "window.h"

namespace GR {
	class Game {
		GR::Window window;
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