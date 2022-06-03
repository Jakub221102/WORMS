# include "weapons.h"
# include <cmath>



//mouseTimeHold is float(0-1.5) that tells how long was activating grenade button clicked. It affects starting velocity
void Grenade::putStartingVelocity(sf::Vector2f mousePosition, float MouseTimeHold)
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

    double ClickedVecLen = sqrt(pow(DistanceX, 2) + pow(DistanceY, 2));

    float VelY = (maxStartingVelLen * DistanceY) / ClickedVecLen;
    float VelX = (maxStartingVelLen * DistanceX) / ClickedVecLen;

    sf::Vector2f StartingVelVec;
    StartingVelVec.x = (VelX * MouseTimeHold) / maxHoldingTime;
    StartingVelVec.y = (VelY * MouseTimeHold) / maxHoldingTime;
    putVelocity(StartingVelVec);
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

unsigned Baseball::FindLeftNearest(sf::Vector2f hitPos)
{
    float baseballX = hitPos.x;
    float baseballY = hitPos.y;
    unsigned IndexOfNearest=100;//code for not found
    float DistanceOfNearest = 9999;
    for (int i = 0; i < getWormVector().size(); i++)
    //{
    //    Worm worm = WormVector[i];
    //    sf::Vector2f WormPos = worm.getPosition();
    //    if (abs(WormPos.y - baseballY) > getHeigthDifference()) { continue; }
    //    float distance = baseballX - WormPos.x;
    //    if ((distance < DistanceOfNearest)&&(distance > 0.5))
    //    {
    //        IndexOfNearest = i;
    //        DistanceOfNearest = distance;
    //    }
    //}
    if (DistanceOfNearest > getRange()) { return 100; }
    return IndexOfNearest;
}

void Baseball::leftHit(sf::Vector2f hitPos)
{
    unsigned indexOfNearest = FindLeftNearest(hitPos);
    if (indexOfNearest == 100) { return; }
    //Worm hitWorm = WormVector[indexOfNearest];
    //hitWorm.putVelocity(-5, 5);
    //hitWorm.TakeDamage(getDamage());
}




unsigned Baseball::FindRightNearest(sf::Vector2f hitPos)
{
    float baseballX = hitPos.x;
    float baseballY = hitPos.y;
    unsigned IndexOfNearest = 100; //code for not found
    float DistanceOfNearest = 9999;

    //for (int i = 0; i < getWormVector().size(); i++)
    //{
    //    Worm worm = WormVector[i];
    //    sf::Vector2f WormPos = worm.getPosition();
    //    if (abs(WormPos.y - baseballY) > getHeigthDifference()) { continue; }
    //    float distance = WormPos.x - baseballX;
    //    if ((distance < DistanceOfNearest) && (distance > 0.5))
    //    {
    //        IndexOfNearest = i;
    //        DistanceOfNearest = distance;
    //    }
    //}
    if (DistanceOfNearest > getRange()) { return 100; }
    return IndexOfNearest;
}

void Baseball::rightHit(sf::Vector2f hitPos)
{
    unsigned indexOfNearest = FindRightNearest(hitPos);
    if (indexOfNearest == 100) { return; }
    //Worm hitWorm = WormVector[indexOfNearest];
    //hitWorm.putVelocity(5, 5);
    //hitWorm.TakeDamage(getDamage());
}