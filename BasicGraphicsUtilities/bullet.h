 #include "dynamic_game_object.h"

//bullet is created with starting vel
class Bullet : public GR::DynamicObject
{
private:
	sf::Vector2f velVec;
	const float MaxBulletVel=999;
public:
	void setVelocity(sf::Vector2f mouseClickedPos);
	void update();
	Bullet(b2World& world, const float& time, std::vector<std::pair<float, float>> vertices, std::string texture_path, sf::Vector2f& mousePosition)
		:GR::DynamicObject(world, time, vertices, texture_path), GR::StaticObject(time, vertices, texture_path)
	{
		setVelocity(mousePosition);
	}
};

void Bullet::setVelocity(sf::Vector2f mouseClickedPos)
{
	sf::Vector2f pistolPos = getPosition();
	float DistanceX = mouseClickedPos.x - pistolPos.x;
	float DistanceY = mouseClickedPos.y - pistolPos.y;

	double ClickedVecLen = sqrt(pow(DistanceX, 2) + pow(DistanceY, 2));

	double VelY = (MaxBulletVel * DistanceY) / ClickedVecLen;
	double VelX = (MaxBulletVel * DistanceX) / ClickedVecLen;
	sf::Vector2f vel = { (float)VelX, (float)VelY };
	velVec = vel;
	putVelocity(vel);
}

void Bullet::update()
{
    static_cast<GR::DynamicObject&>(*this).update();
	putVelocity(velVec);
}