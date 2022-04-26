#include "game.h"

sf::Time GR::Game::getElapsed() {
	return elapsed;
}

float GR::Game::getElapsedSeconds() {
	return elapsed.asSeconds();
}

void GR::Game::restartClock() {
	elapsed = clock.restart();
}

void GR::Game::update(float time) {
	window.update(time);
}