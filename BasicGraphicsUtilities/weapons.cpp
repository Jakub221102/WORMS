# include "weapons.h"


//mouseTimeHold is float(0-1.5) that tells how long was activating grenade button clicked. It affects starting velocity
void Grenade::putStartingVelocity(sf::Vector2i mousePosition, float MouseTimeHold)
{
    if (MouseTimeHold < 0) { throw std::invalid_argument("Given time is incorrect"); }
    if (MouseTimeHold > 1.5) { MouseTimeHold = 1.5; }
    //to give grenade more starting vel edit
    float maxStartingVelLen = 10;
    float maxHoldingTime = 1.5;

    float mouseClickedY = mousePosition.y;
    float mouseClickedX = mousePosition.x;

    sf::Vector2f ThrowPosition = getPosition();

    float DistanceX = mouseClickedX - ThrowPosition.x;
    float DistanceY = mouseClickedY - ThrowPosition.y;

    float ClickedVecLen = sqrt(pow(DistanceX, 2) + pow(DistanceY, 2));

    float VelY = (maxStartingVelLen * DistanceY) / ClickedVecLen;
    float VelX = (maxStartingVelLen * DistanceX) / ClickedVecLen;

    sf::Vector2f StartingVelVec;
    StartingVelVec.x = (VelX * MouseTimeHold) / maxHoldingTime;
    StartingVelVec.y = (VelY * MouseTimeHold) / maxHoldingTime;
    putVelocity(StartingVelVec);
}

//funkcja ma z założenia dostęp do vectora wormów w gierce
void Grenade::GrenadeExplosion();
{
    sf::Vector2f position = getPosition();
    const float posX = position.x;
    const float posY = position.y;
    //Distance scale is recoil ratio
    float DistanceScale = 5;
    for (const auto& Worm : WormVector)
    {
        sf::Vector2f wormPos = Worm.getPosition();
        float WormDistance = sqrt(pow(posX - wormPos.x, 2) + pow(posY - wormPos.y, 2));
        if (WormDistance < DistanceScale * 6) { Worm.TakeDamage(10); }
        if (WormDistance < DistanceScale * 4) { Worm.TakeDamage(10); }
        if (WormDistance < DistanceScale * 2)
        {
            Worm.TakeDamage(10);
            sf::Vector2f wormPos Worm.getPosition();
            sf::Vector2f RecoilVel((wormPos.x - posX) / 2, (wormPos.y - posY ) /2);
            Worm.putVelocity(RecoilVel);
        }
        if (WormDistance < DistanceScale * 1) { Worm.TakeDamage(10); }
    }
}



void Grenade::update()
{
    static_cast<GR::DynamicObject&>(*this).update();
    IncCurrentTime(deltaTime);
    if (GetCurrentTime() > GetExplosionTime())
    {
        GrenadeExplosion();
    }

}



Grenade::Grenade(b2World& world, const float& time, std::vector<std::pair<float, float>> vertices, std::string texture_path,
    sf::Vector2f& startingPos, sf::Vector2f& mousePosition, float MouseTimeHold);
    :GR::DynamicObject(world, time, vertices, texture_path)
{
    const float circleSize = 1;
    b2BodyDef def;
    def.type = b2_dynamicBody;
    def.position.Set(startingPos.x, startingPos.y);
    body = world.CreateBody(&def);
    b2CircleShape circleShape;
    circleShape.m_radius= circleSize;
    body->CreateFixture(&circleShape, 1);

    setPosition(startingPos);
    putStartingVelocity(sf::Vector2i mousePosition, float MouseTimeHold);
}
