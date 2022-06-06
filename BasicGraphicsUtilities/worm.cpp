#include "worm.h"
#include <cmath>
GR::RealTimeKeyboardManager<Worm, sf::Keyboard::Key> Worm::inputManager = {};
GR::EventManager<Worm, sf::Keyboard::Key> Worm::eventManager = {};

std::vector<std::pair<float, float>> gun_v{
	{0.0f, 0.0f},
	{13.4f, 0.0f},
	{13.4f, 6.1f},
	{0.0f, 6.1f}
};

std::vector<std::pair<float, float>> base_v{
	{0.0f, 0.0f},
	{16.3f, 0.0f},
	{16.3f, 11.4f},
	{0.0f, 11.4f}
};

std::vector<std::pair<float, float>> gren_v{
	{0.0f, 0.0f},
	{0.5f * 16.0f, 0.0f},
	{0.5f * 16.0f, 0.5f * 23.0f},
	{0.0f, 0.5f * 23.0f}
};


Worm::Worm(b2World& world, const float& time, std::vector<std::pair<float, float>> vertices, std::string texture_path)
	: DynamicAnimatedObject(world, time, vertices, texture_path, true), StaticObject(time, vertices, texture_path), pointer(0) {
	equipment.push_back(std::make_unique<GR::StaticObject>(time, gun_v, "animacje/gunleft.png"));
	equipment.push_back(std::make_unique<GR::StaticObject>(time, gun_v, "animacje/gunright.png"));
	equipment.push_back(std::make_unique<GR::StaticObject>(time, base_v, "animacje/baseballright.png"));
	equipment.push_back(std::make_unique<GR::StaticObject>(time, base_v, "animacje/baseballeft.png"));
	equipment.push_back(std::make_unique<GR::StaticObject>(time, gren_v, "animacje/granade.png"));
	equipment.push_back(std::make_unique<GR::StaticObject>(time, gren_v, "animacje/granade.png"));
}

void Worm::jump() {
	std::vector<float> arguments = inputManager.getArguments(sf::Keyboard::Space);
	if (jumpCooldown == 0)
	{
		b2Vec2 velo = box2dModel->getVelocity();
		putVelocity({ velo.x, 0 });
		box2dModel->putImpulseToCenter({ arguments[0], arguments[1] * 400 });
		jumpCooldown = 7000;
	}
}

void Worm::move_right() {
	std::vector<float> arguments = inputManager.getArguments(sf::Keyboard::Right);
	b2Vec2 velocity = box2dModel->getVelocity();
	if (velocity.x < 30)
	{
		box2dModel->addVelocity({ arguments[0], arguments[1] });
	}
}

void Worm::move_left() {
	std::vector<float> arguments = inputManager.getArguments(sf::Keyboard::Left);
	b2Vec2 velocity = box2dModel->getVelocity();
	if (velocity.x > -30)
	{
		box2dModel->addVelocity({ arguments[0], arguments[1] });
	}
}

void Worm::move_down() {
	std::vector<float> arguments = inputManager.getArguments(sf::Keyboard::Down);
	b2Vec2 velocity = box2dModel->getVelocity();
	if (velocity.y > -10)
	{
		box2dModel->addVelocity({ arguments[0], arguments[1] });
	}
}

void Worm::update(float mouseX, float mouseY) {
	updateNoControl();
	updateCooldowns();
	listenAndUseAll();
	sf::Vector2f pos = getPosition();
	sf::Vector2f direction = { mouseX - pos.x, mouseY - pos.y };
	direction = (1.0f / sqrtf(direction.x * direction.x + direction.y * direction.y)) * direction;
	float dotP = direction.x * 1.0f;
	//int rotation = mouseY > pos.y ? std::acos(dotP) : -std::acos(dotP);
	float rotation;
	if (mouseX > pos.x) {
		rotation = mouseY > pos.y ? std::acos(dotP) : -std::acos(dotP);
	}
	else {
		rotation = mouseY > pos.y ? std::acos(dotP) : -std::acos(dotP);
		rotation += 3.1415;
	}
	std::cout << rotation << std::endl;
	ptrprim = mouseX > pos.x ? pointer + 1 : pointer;
	equipment[ptrprim]->setPosition(pos + (8.0f*direction));
	equipment[ptrprim]->setRotation(rotation*180.0f/3.1415);

}

void Worm::updateNoControl() {
	static_cast<GR::DynamicAnimatedObject&>(*this).update();
	text->setString(std::to_string(hp) + '%');
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

GR::StaticObject& Worm::getCurrentWeapon() {
	if(ptrprim != -1)
		return *equipment[ptrprim];
}

void Worm::updateCooldowns()
{
	if (jumpCooldown > 0)
	{
		--jumpCooldown;
	}
}

void Worm::pickWeapon1() {
	pointer = 0;
}

void Worm::pickWeapon2() {
	pointer = 2;
}

void Worm::pickWeapon3() {
	pointer = 4;
}