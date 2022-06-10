#include "game.h"

Game::Game(const float& deltaTime)
	: deltaTime(deltaTime), currentWorm(0), time(0), status(Stage::BREAK){

}
void Game::addKeyBinding(sf::Keyboard::Key keyCode, void (Game::* pointer)()) {
	keyBindings.addBinding(keyCode, pointer);
}

void Game::removeKeyBinding(sf::Keyboard::Key keyCode) {
	keyBindings.removeBinding(keyCode);
}

void Game::endBreak() {
	if (status == Stage::BREAK) {
		status = Stage::TURN;
	}
}

Worm::Type decodeWinner(unsigned char mask) {
	switch (mask)
	{
	case 0:
		return Worm::Type::DRAW;
	case 1:
		return Worm::Type::BRITISH;
	case 2:
		return Worm::Type::GERMAN;
	case 4:
		return Worm::Type::POLISH;
	case 8:
		return Worm::Type::SOVIET;
	default:
		return Worm::Type::NONE;
	}
}

void Game::listenAndUseAll() {
	keyBindings.listenAndUseAllKeys(*this);
}

Worm::Type Game::update(std::vector<std::unique_ptr<Worm>>& worms, GR::StaticAnimatedRelativeObject& timer, float mousex, float mousey) {
	time += deltaTime;
	unsigned char mask = {};
	for (int i = 0; i < worms.size(); i++) {
		if (worms[i]->getPosition().y > 1500.0f)
			worms[i]->setHealthPoints(0);
		if (worms[i]->getHealthPoints() > 0) {
			switch (worms[i]->getType())
			{
			case Worm::Type::BRITISH:
				mask |= 1;
				break;
			case Worm::Type::GERMAN:
				mask |= 2;
				break;
			case Worm::Type::POLISH:
				mask |= 4;
				break;
			case Worm::Type::SOVIET:
				mask |= 8;
				break;
			}
		}
	}
	//std::cout << static_cast<int>(mask) << std::endl;
	Worm::Type winner = decodeWinner(mask);
	if (winner != Worm::Type::NONE) return winner;
	listenAndUseAll();
	timer.update();
	switch (status) {
	case Stage::BREAK:
		time = 0.0f;
		timer.zeroAnimation();
		for (auto& worm : worms)
			worm->updateNoControl();
		worms[currentWorm]->enableShooting();
		break;
	case Stage::TURN:
		if (time >= 30.0f || worms[currentWorm]->getHealthPoints() <= 0) {
			worms[currentWorm]->inactivate();
			do {
				currentWorm = (currentWorm + 1) % worms.size();
			} while (worms[currentWorm]->getHealthPoints() <= 0);
			status = Stage::BREAK;
		}
		else {
			worms[currentWorm]->activate();
			for (int i = 0; i < worms.size(); i++)
				if (i != currentWorm)
					worms[i]->updateNoControl();
				else
					worms[i]->update(mousex, mousey);
		}
	}
	return Worm::Type::NONE;
}