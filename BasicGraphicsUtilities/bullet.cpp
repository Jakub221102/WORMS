#include "worm.h"

Bullet::Bullet(b2World& world, const float& time, std::vector<std::pair<float, float>> vertices, std::string texture_path, sf::Vector2f direction)
	:GR::DynamicAnimatedObject(world, time, vertices, texture_path), StaticObject(time, vertices, texture_path), isLive(true)
{
	box2dModel->setAsBullet();
	setShotVelocity(direction);
}



void Bullet::setShotVelocity(sf::Vector2f direction)
{

	double ClickedVecLen = sqrt(pow(direction.x, 2) + pow(direction.y , 2));

	double VelY = (MaxBulletVel * direction.y) / ClickedVecLen;
	double VelX = (MaxBulletVel * direction.x) / ClickedVecLen;
	sf::Vector2f vel = { (float)VelX, (float)VelY };
	velVec = vel;
	putVelocity(vel);
}


void Bullet::update()
{
	static_cast<GR::DynamicAnimatedObject&>(*this).update();
	putVelocity(velVec);
}

/*
Bullet::~Bullet()
{
	
}
*/