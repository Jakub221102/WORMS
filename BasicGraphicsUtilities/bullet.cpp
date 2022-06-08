#include "worm.h"

Bullet::Bullet(b2World& world, const float& time, std::vector<std::pair<float, float>> vertices, std::string texture_path, sf::Vector2f mousePosition)
	:GR::DynamicAnimatedObject(world, time, vertices, texture_path), StaticObject(time, vertices, texture_path), isLive(true)
{
	box2dModel->setAsBullet();
	setShotVelocity(mousePosition);
}



void Bullet::setShotVelocity(sf::Vector2f mouseClickedPos)
{
	sf::Vector2f pistolPos = getPosition();
	float DistanceX = mouseClickedPos.x - pistolPos.x;
	float DistanceY = pistolPos.y - mouseClickedPos.y;

	double ClickedVecLen = sqrt(pow(DistanceX, 2) + pow(DistanceY, 2));

	double VelY = (MaxBulletVel * DistanceY) / ClickedVecLen;
	double VelX = (MaxBulletVel * DistanceX) / ClickedVecLen;
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