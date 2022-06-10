#include "worm.h"
#include <cmath>
#include "sound_manager.h"

#define JUMPSPEED 1500.0f

GR::RealTimeKeyboardManager<Worm, sf::Keyboard::Key> Worm::inputManager = {};
GR::EventManager<Worm, sf::Keyboard::Key> Worm::eventManager = {};
GR::RealTimeMouseManager<Worm, sf::Mouse::Button> Worm::mouseManager = {};

//static GR::SoundManager sounds("SoundEffects/sounds.txt");

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

unsigned int Worm::getHealthPoints() const {
	return hp;
}

Worm::Type Worm::getType() const {
	return team;
}

Worm::Worm(b2World& world, const float& time, std::vector<std::pair<float, float>> vertices, std::string texture_path)
	: DynamicAnimatedObject(world, time, vertices, texture_path, true), StaticObject(time, vertices, texture_path), pointer(0) {
	equipment.push_back(std::make_unique<GR::StaticObject>(time, gun_v, "animacje/gunleft.png"));
	equipment.push_back(std::make_unique<GR::StaticObject>(time, gun_v, "animacje/gunright.png"));
	equipment.push_back(std::make_unique<GR::StaticObject>(time, base_v, "animacje/baseballright.png"));
	equipment.push_back(std::make_unique<GR::StaticObject>(time, base_v, "animacje/baseballeft.png"));
	equipment.push_back(std::make_unique<GR::StaticObject>(time, gren_v, "animacje/granade.png"));
	equipment.push_back(std::make_unique<GR::StaticObject>(time, gren_v, "animacje/granade.png"));
	if (texture_path.find("sov") != std::string::npos) team = Type::SOVIET;
	else if (texture_path.find("ger") != std::string::npos) team = Type::GERMAN;
	else if (texture_path.find("pol") != std::string::npos) team = Type::POLISH;
	else if (texture_path.find("brit") != std::string::npos) team = Type::BRITISH;
	else throw WrongNameException("Wrong name exception!");
}

void Worm::setJumpReady()
{
	jumpReady = JumpState::ready;
	jumpCooldown = 0;
}

void Worm::setHalfJump()
{
	jumpReady = JumpState::oneLeft;
	jumpCooldown = 0;
}

void Worm::inactivate() {
	isActive = false;
}

void Worm::enableShooting() {
	canShoot = true;
}

void Worm::disableShooting() {
	canShoot = false;
}

bool Worm::readyShot() const {
	return canShoot;
}

void Worm::activate() {
	isActive = true;
}

bool Worm::active() const {
	return isActive;
}

void Worm::jump() {
	std::vector<float> arguments = inputManager.getArguments(sf::Keyboard::W);
	if (jumpCooldown <= 0 && jumpReady < JumpState::noneLeft)
	{	
		b2Vec2 velo = box2dModel->getVelocity();
		putVelocity({ velo.x, 0 });
		box2dModel->putImpulseToCenter({ arguments[0], arguments[1] * 400 });
		jumpCooldown = 0.5;
		if (jumpReady == JumpState::ready) { jumpReady = JumpState::oneLeft; }
		else { jumpReady = JumpState::noneLeft; }
	}
}

void Worm::move_right() {
	std::vector<float> arguments = inputManager.getArguments(sf::Keyboard::D);
	b2Vec2 vel = box2dModel->getVelocity();

	//float angle = box2dModel->getAngle();
	//float relVelX = cos(angle) * velocity.x + sin(angle) * velocity.y;

	if (vel.x < 30) // 30 -> it can by arguments[0]
	{
		if (jumpReady == JumpState::ready && vel.y > 20) // 20 -> it can be arguement [1]
		{
			box2dModel->putVeloY( 20 );
		}
		box2dModel->putVeloX( 30 );
	}
}

void Worm::move_left() {
	std::vector<float> arguments = inputManager.getArguments(sf::Keyboard::A);
	b2Vec2 vel = box2dModel->getVelocity();
	if (vel.x > -30) // -30 -> it can by arguments[0]
	{
		if (jumpReady == JumpState::ready && vel.y > 20) // 20 -> it can be arguement [1]
		{
			box2dModel->putVeloY(20);
		}
		box2dModel->putVeloX(-30);
	}
}

void Worm::move_down() {
	std::vector<float> arguments = inputManager.getArguments(sf::Keyboard::S);
	b2Vec2 velocity = box2dModel->getVelocity();
	if (velocity.y > -30)
	{
		box2dModel->addVelocity({ arguments[0], arguments[1] });
	}
}

void Worm::setHealthPoints(unsigned int hp) {
	this->hp = hp;
}

void Worm::shot()
{
	if (!canShoot) return;
	canShoot = false;
	std::vector<float> arguments = mouseManager.getArguments(sf::Mouse::Left);
	const sf::Vector2f& mousePos = { arguments[0], arguments[1] };
	//std::cout << arguments[0] << ' ' << arguments[1] << std::endl;
	if (!bullet) {
		sf::Vector2f start = getPosition();
		sf::Vector2f direction(mousePos.x - start.x, start.y - mousePos.y );	//reversed y for box2d 
		
		float angle = -atan2(direction.x , -direction.y) + 1.5; //angular offset of our world
		
		float x_offset = cos(angle) * 15; // 10 is a radius (pistol length)
		float y_offset = sin(angle) * 20;

	
		std::cout <<"angle: \t " << angle << std::endl;


		std::vector<std::pair<float, float>> vertices{
		{start.x - 1 + x_offset, start.y + 1 + y_offset},
		{start.x + 1 + x_offset, start.y + 1 + y_offset},
		{start.x + 1 + x_offset, start.y - 1 + y_offset},
		{start.x - 1 + x_offset, start.y - 1 + y_offset}
		};

		b2World* world = box2dModel->getWorld();

		bullet = std::make_unique<Bullet>( *world, deltaTime, vertices, "animacje/bulet.png", direction );
	}
}

void Worm::destroyBullet()
{
	//auto call destructor of class Model (delete body from the b2World), not allowed to do during time step
	bullet.reset();
}

GR::StaticObject& Worm::drawableBullet()
{
	return static_cast<GR::StaticObject&>(*bullet);
}


bool Worm::hasBullet()
{
	if (bullet) { return true; }
	else { return false; }
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
	// fatalny kawa³ek kodu ale jest 3:33
	auto velocity = box2dModel->getVelocity();
	rotation = mouseY > pos.y ? std::acos(dotP) : -std::acos(dotP);
	if (velocity.x * velocity.x + velocity.y * velocity.y >= JUMPSPEED) {
		setCurrentAnimation("JUMP", true);
	}
	else if (mouseX > pos.x) {
		setCurrentAnimation("RIGHT", true);
	}
	else {
		//rotation = mouseY > pos.y ? std::acos(dotP) : -std::acos(dotP);
		setCurrentAnimation("LEFT", true);
		rotation += 3.1415;
	}
	//std::cout << rotation << std::endl;
	ptrprim = mouseX > pos.x ? pointer + 1 : pointer;
	equipment[ptrprim]->setPosition(pos + (8.0f*direction));
	equipment[ptrprim]->setRotation(rotation*180.0f/3.1415);

}

void Worm::updateNoControl() {
	static_cast<GR::DynamicAnimatedObject&>(*this).update();
	auto velocity = box2dModel->getVelocity();
	if (hp <= 0)
		setCurrentAnimation("COFFIN");
	else if (velocity.x * velocity.x + velocity.y * velocity.y >= JUMPSPEED)
		setCurrentAnimation("JUMP");
	else setCurrentAnimation("WORM", true);
	text->setString(std::to_string(hp) + '%');
	contactHandler();
	if (bullet)
	{
		if (bullet->isLive)
		{
			bulletContactHandler();
			bullet->update();
		}
		else 
		{
			destroyBullet();
		}
	}
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

void Worm::addKeyBinding(sf::Mouse::Button keyCode, void (Worm::* pointer)(), InputType type) {
	mouseManager.addBinding(keyCode, pointer);
}
//
void Worm::removeKeyBinding(sf::Mouse::Button keyCode, InputType type) {
	mouseManager.removeBinding(keyCode);
}

void Worm::setKeyArguments(sf::Mouse::Button keyCode, const std::vector<float>& args, InputType type) {
	mouseManager.setArguments(keyCode, args);
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
	mouseManager.listenAndUseAllMouseButtons(*this);
}

GR::StaticObject& Worm::getCurrentWeapon() {
	if(ptrprim != -1)
		return *equipment[ptrprim];
}

void Worm::updateCooldowns()
{
	if (jumpCooldown > 0)
	{
		jumpCooldown -= deltaTime;
	}
	//if (bulletStepCooldown > 0)
	//{
	//	bulletStepCooldown--;
	//}
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


void Worm::TakeDamage(int dmg)
{
	if (hp > 0)
	{
		hp -= dmg;
	}
}