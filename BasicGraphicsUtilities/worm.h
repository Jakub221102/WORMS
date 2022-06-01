#pragma once

#include "dynamic_animated_object.h"

enum class InputType {
	REALTIME,
	EVENTKEYBOARD,
};

class Worm : public GR::DynamicAnimatedObject {
	static GR::RealTimeKeyboardManager<Worm, sf::Keyboard::Key> inputManager;
	static GR::EventManager<Worm, sf::Keyboard::Key> eventManager;
public:
	Worm(b2World& world, const float& time, std::vector<std::pair<float, float>> vertices, std::string texture_path);
    // Bindings
	static void addKeyBinding(sf::Keyboard::Key keyCode, void (Worm::* pointer)(), InputType type);
	static void removeKeyBinding(sf::Keyboard::Key keyCode, InputType type);
	static void setKeyArguments(sf::Keyboard::Key keyCode, const std::vector<float>& args, InputType type);
	void listenAndUseAll();
	void update();
	void updateNoControl();
	// Gameplay functions
	void jump();
	void move_right();
	void move_left();
	void move_down();

};
GR::RealTimeKeyboardManager<Worm, sf::Keyboard::Key> Worm::inputManager = {};
GR::EventManager<Worm, sf::Keyboard::Key> Worm::eventManager = {};

Worm::Worm(b2World& world, const float& time, std::vector<std::pair<float, float>> vertices, std::string texture_path) 
	: DynamicAnimatedObject(world, time, vertices, texture_path), StaticObject(time, vertices, texture_path){

}

void Worm::jump() {
	std::vector<float> arguments = inputManager.getArguments(sf::Keyboard::Space);
	putVelocity({ arguments[0], arguments[1] });
}

void Worm::move_right() {
	std::vector<float> arguments = inputManager.getArguments(sf::Keyboard::Right);
	putVelocity({ arguments[0], arguments[1] });
}

void Worm::move_left() {
	std::vector<float> arguments = inputManager.getArguments(sf::Keyboard::Left);
	putVelocity({ arguments[0], arguments[1] });
}

void Worm::move_down() {
	std::vector<float> arguments = inputManager.getArguments(sf::Keyboard::Down);
	putVelocity({ arguments[0], arguments[1] });
}

void Worm::update() {
	static_cast<GR::DynamicAnimatedObject&>(*this).update();
	listenAndUseAll();
}

void Worm::updateNoControl() {
	static_cast<GR::DynamicAnimatedObject&>(*this).update();
	
}

void Worm::addKeyBinding(sf::Keyboard::Key keyCode, void (Worm::* pointer)(), InputType type) {
	switch (type) {
		case InputType::REALTIME:
			inputManager.addBinding(keyCode, pointer);
			break;
		case InputType::EVENTKEYBOARD:
			eventManager.addBinding(keyCode, pointer);
	}
}

void Worm::removeKeyBinding(sf::Keyboard::Key keyCode, InputType type) {
	switch (type) {
	case InputType::REALTIME:
		inputManager.removeBinding(keyCode);
		break;
	case InputType::EVENTKEYBOARD:
		eventManager.removeBinding(keyCode);
	}
}


void Worm::setKeyArguments(sf::Keyboard::Key keyCode, const std::vector<float>& args, InputType type) {
	switch (type) {
	case InputType::REALTIME:
		inputManager.setArguments(keyCode, args);
		break;
	case InputType::EVENTKEYBOARD:
		eventManager.setArguments(keyCode, args);
	}
}

void Worm::listenAndUseAll() {
	inputManager.listenAndUseAllKeys(*this);
}
