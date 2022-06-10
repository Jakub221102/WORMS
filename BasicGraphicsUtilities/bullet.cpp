#include "worm.h"

Bullet::Bullet(b2World& world, const float& time, std::vector<std::pair<float, float>> vertices, std::string texture_path, sf::Vector2f direction)
	:GR::DynamicAnimatedObject(world, time, vertices, texture_path), StaticObject(time, vertices, texture_path), isLive(true)
{

	box2dModel->setAsBullet();
	setShotVelocity(direction);
}

//WeaponType Bullet::type()
//{
//	return WeaponType::basic;
//}

void Bullet::setShotVelocity(sf::Vector2f direction)
{
	double ClickedVecLen = sqrt(pow(direction.x, 2) + pow(direction.y, 2));

	double VelY = direction.y / ClickedVecLen;	//sin
	double VelX = direction.x / ClickedVecLen;	//cos
	sf::Vector2f vel = { (float)VelX, (float)VelY };
	velVec = vel;
}


void Bullet::update()
{
	static_cast<GR::DynamicAnimatedObject&>(*this).update();
	putVelocity({ velVec.x * MaxBasicVel, velVec.y * MaxBasicVel });
}


Bullet::~Bullet()
{

}




Baseball::Baseball(b2World& world, const float& time, std::vector<std::pair<float, float>> vertices, std::string texture_path, sf::Vector2f direction)
	: Bullet(world, time, vertices, texture_path, direction), StaticObject(time, vertices, texture_path)
{
	WeaponType type = WeaponType::baseball;
}

void Baseball::update()
{
	static_cast<GR::DynamicAnimatedObject&>(*this).update();
	isLive = false;
}

Baseball::~Baseball()
{

}


Granade::Granade(b2World& world, const float& time, std::vector<std::pair<float, float>> vertices, std::string texture_path, sf::Vector2f direction)
	: Bullet(world, time, vertices, texture_path, direction), StaticObject(time, vertices, texture_path), detonatorCooldown(10)
{
	WeaponType type = WeaponType::granade;
	putVelocity({ velVec.x * MaxGranadeVel, velVec.y * MaxGranadeVel * 2 });
}

//WeaponType Granade::type()
//{
//	return WeaponType::granade;
//}


void Granade::update()
{
	if (detonatorCooldown < 0)
	{
		//blow();
	}
	else
	{
		detonatorCooldown -= deltaTime;
	}
	static_cast<GR::DynamicAnimatedObject&>(*this).update();

}

void blow()
{

}

Granade::~Granade()
{

}