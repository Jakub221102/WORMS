#pragma once

#include <memory>
#include <cmath>

#include "dynamic_animated_object.h"

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
	friend class Worm;

protected:
	WeaponType type = WeaponType::basic;
	const float MaxBasicVel = 100;
	const float MaxGranadeVel = 40;

	bool isLive;
	sf::Vector2f velVec;

public:
	Bullet(b2World& world, const float& time, std::vector<std::pair<float, float>> vertices, std::string texture_path, sf::Vector2f direction);
	virtual ~Bullet();
	//virtual WeaponType type();
	void setShotVelocity(sf::Vector2f direction);
	virtual void update();
};

class Baseball : public Bullet
{
public:
	Baseball(b2World& world, const float& time, std::vector<std::pair<float, float>> vertices, std::string texture_path, sf::Vector2f direction);
	~Baseball();
	void update() override;

};


class Granade : public Bullet
{
	std::unique_ptr<Bullet> particles = nullptr;
	float detonatorCooldown; //set in consturctor
	//int particlesLifetime; //set in consturctor

public:
	Granade(b2World& world, const float& time, std::vector<std::pair<float, float>> vertices, std::string texture_path, sf::Vector2f direction);
	~Granade();
	//WeaponType type();
	void update() override;
	void blow();
};

class WrongNameException : public std::exception {
	std::string message;
public:
	WrongNameException(const std::string& message) : message(message) {}
	const char* what() const noexcept { return message.c_str(); }
};

class Worm : public GR::DynamicAnimatedObject {
public:
	enum class Type {
		NONE,
		POLISH,
		SOVIET,
		GERMAN,
		BRITISH,
		DRAW
	};
private:
	static GR::RealTimeKeyboardManager<Worm, sf::Keyboard::Key> inputManager;
	static GR::EventManager<Worm, sf::Keyboard::Key> eventManager;
	static GR::RealTimeMouseManager<Worm, sf::Mouse::Button> mouseManager;
	std::vector<std::unique_ptr<GR::StaticObject>> equipment;
	GR::StaticObject* currentWeapon;
	int pointer;
	int ptrprim;
	unsigned hp = 100;
	float jumpCooldown = 0;
	float weaponCooldown = 0;
	float dmgCooldown = 0;
	//int bulletStepCooldown = 3;
	JumpState jumpReady = JumpState::noneLeft;
	WeaponType weapon = WeaponType::basic;
	std::unique_ptr<Bullet> bullet = nullptr;
	Type team;
	bool isActive = false;
	bool canShoot = true;
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
	void setHalfJump();
	unsigned int getHealthPoints() const;
	Type getType() const;
	void inactivate();
	void activate();
	bool active() const;
	bool readyShot() const;
	void enableShooting();
	void disableShooting();
	void setHealthPoints(unsigned int hp);
	GR::StaticObject& getCurrentWeapon();
};
