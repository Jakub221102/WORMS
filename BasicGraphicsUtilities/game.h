#pragma once
#include "worm.h"
#include "window.h"
#include "input_manager.h"
#include "static_animated_relative_object.h"
#include "world.h"
#include <list>

class Game {
public:
	enum class Stage {
		BREAK,
		TURN
	};
	GR::RealTimeKeyboardManager<Game, sf::Keyboard::Key> keyBindings = {};
	const float& deltaTime;
	float time;
	int currentWorm;
	Stage status;
	//std::lis
public:
	void addKeyBinding(sf::Keyboard::Key keyCode, void (Game::* pointer)());
	void removeKeyBinding(sf::Keyboard::Key keyCode);
	void listenAndUseAll();
	void endBreak();
	Game(const float& deltaTime);
	Worm::Type update(std::vector<std::unique_ptr<Worm>>& worms, GR::StaticAnimatedRelativeObject& timer, float mousex, float mousey);
};
