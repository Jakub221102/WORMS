#pragma once

#include "dynamic_animated_object.h"
//#include "bullet.h"

#include <memory>
//#include "weapons.h"
//#include "static_object_relative.h"

enum class InputType {
	REALTIME,
	EVENTKEYBOARD,
	EVENTMOUSE
};

enum class JumpState {
	ready,
	oneLeft,
	noneLeft
};

enum class WeaponType {
	basic,
	baseball,
	granade
};


//bullet is created with starting vel
class Bullet : public GR::DynamicAnimatedObject
{
private:

	friend class Worm;

	sf::Vector2f velVec;
	const float MaxBulletVel = 50;
public:
	void setShotVelocity(sf::Vector2f mouseClickedPos);
	void update();
	Bullet(b2World& world, const float& time, std::vector<std::pair<float, float>> vertices, std::string texture_path, sf::Vector2f mousePosition);
	//~Bullet();
};


class Worm : public GR::DynamicAnimatedObject {
	static GR::RealTimeKeyboardManager<Worm, sf::Keyboard::Key> inputManager;
	static GR::EventManager<Worm, sf::Keyboard::Key> eventManager;
	static GR::RealTimeMouseManager<Worm, sf::Mouse::Button> mouseManager;
	std::vector<std::unique_ptr<GR::StaticObject>> equipment;
	GR::StaticObject* currentWeapon;
	int pointer;
	int ptrprim;
	unsigned hp = 100;
	float jumpCooldown = 0;
	JumpState jumpReady = JumpState::noneLeft;
	WeaponType weapon = WeaponType::basic;
	std::unique_ptr<Bullet> bullet = nullptr;

public:
	
	Worm(b2World& world, const float& time, std::vector<std::pair<float, float>> vertices, std::string texture_path);
    // Bindings
	static void addKeyBinding(sf::Keyboard::Key keyCode, void (Worm::* pointer)(), InputType type);
	static void addKeyBinding(sf::Mouse::Button keyCode, void (Worm::* pointer)(), InputType type);
	static void removeKeyBinding(sf::Keyboard::Key keyCode, InputType type);
	static void removeKeyBinding(sf::Mouse::Button keyCode, InputType type);
	static void setKeyArguments(sf::Keyboard::Key keyCode, const std::vector<float>& args, InputType type);
	static void setKeyArguments(sf::Mouse::Button keyCode, const std::vector<float>& args, InputType type);
	void listenAndUseAll();
	void update(float mouseX, float mouseY);
	void updateNoControl();
	bool hasBullet();
	// Gameplay functions
	//void addEquipment(const std::vector<GR::StaticObject>& weapons);
	void jump();
	void move_right();
	void move_left();
	void move_down();
	void shot();
	void destroyBullet();
	GR::StaticObject& drawableBullet();
	void pickWeapon1();
	void pickWeapon2();
	void pickWeapon3();
	void TakeDamage(int dmg);
	void updateCooldowns();
	void contactHandler();
	void bulletContactHandler();
	void setJumpReady();
	GR::StaticObject& getCurrentWeapon();
};
