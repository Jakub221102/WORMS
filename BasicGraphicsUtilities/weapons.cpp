//# include "weapons.h"
//# include <cmath>
//
//
//
////mouseTimeHold is float(0-1.5) that tells how long was activating grenade button clicked. It affects starting velocity
////void Grenade::putStartingVelocity(sf::Vector2f mousePosition, float MouseTimeHold)
////{
////    if (MouseTimeHold < 0) { throw std::invalid_argument("Given time is incorrect"); }
////    if (MouseTimeHold > 1.5) { MouseTimeHold = 1.5; }
////    //to give grenade more starting vel edit
////    float maxStartingVelLen = 10;
////    float maxHoldingTime = 1.5;
////
////    float mouseClickedY = mousePosition.y;
////    float mouseClickedX = mousePosition.x;
////
////    sf::Vector2f ThrowPosition = getPosition();
////
////    float DistanceX = mouseClickedX - ThrowPosition.x;
////    float DistanceY = mouseClickedY - ThrowPosition.y;
////
////    double ClickedVecLen = sqrt(pow(DistanceX, 2) + pow(DistanceY, 2));
////
////    double VelY = (maxStartingVelLen * DistanceY) / ClickedVecLen;
////    double VelX = (maxStartingVelLen * DistanceX) / ClickedVecLen;
////
////    sf::Vector2f StartingVelVec;
////    StartingVelVec.x = (VelX * MouseTimeHold) / maxHoldingTime;
////    StartingVelVec.y = (VelY * MouseTimeHold) / maxHoldingTime;
////    putVelocity(StartingVelVec);
////}
////
////
////void Grenade::update()
////{
////    static_cast<GR::DynamicObject&>(*this).update();
////    IncCurrentTime(deltaTime);
////    if (GetCurrentTime() > GetExplosionTime())
////    {
////        GrenadeExplosion();
////    }
////}
////
////
////void Grenade::GrenadeExplosion()
////{
////    sf::Vector2f position = getPosition();
////    const float posX = position.x;
////    const float posY = position.y;
////    //Distance scale is a damage ratio
////    float DistanceScale = 5;
////    for (Worm &worm:WormVector)
////    {
////        sf::Vector2f wormPos = worm.getPosition();
////        double WormDistance = sqrt(pow(posX - wormPos.x, 2) + pow(posY - wormPos.y, 2));
////        if (WormDistance < DistanceScale * 6) { worm.TakeDamage(10); }
////        if (WormDistance < DistanceScale * 4) { worm.TakeDamage(10); }
////        if (WormDistance < DistanceScale * 2)
////        {
////            worm.TakeDamage(10);
////            sf::Vector2f wormPos = worm.getPosition();
////            sf::Vector2f RecoilVel((wormPos.x - posX) * recoilRatio, (wormPos.y - posY) * recoilRatio);
////            worm.putVelocity(RecoilVel);
////        }
////        if (WormDistance < DistanceScale * 1) { worm.TakeDamage(10); }
////    }
////}
//
////////==================================================================================
////////==================================================================================
////////==================================================================================
////////==================================================================================
////////==================================================================================
//////
//unsigned Baseball::FindLeftNearest(std::vector<std::unique_ptr<Worm>> WormVector)
//{
//    float baseballX = hitPos.x;
//    float baseballY = hitPos.y;
//    unsigned IndexOfNearest = 100;//code for not found
//    float DistanceOfNearest = 999999;
//    for (int i=0;i<WormVector.size();i++)
//    {
//        sf::Vector2f WormPos = WormVector[i]->getPosition();
//        if (abs(WormPos.y - baseballY) > heigthDifference) { continue; }
//        float distance = baseballX - WormPos.x;
//        if ((distance < DistanceOfNearest))
//        {
//            IndexOfNearest = i;
//            DistanceOfNearest = distance;
//        }
//    }
//    if (DistanceOfNearest > range) { return 100; }
//    return IndexOfNearest;
//}
//
//void Baseball::leftHit(std::vector<std::unique_ptr<Worm>> WormVector)
//{
//    unsigned indexOfNearest = FindLeftNearest(WormVector);
//    if (indexOfNearest == 100) { return; }
//    WormVector[indexOfNearest]->TakeDamage(damage);
//    WormVector[indexOfNearest]->putVelocity(-recoil, recoil);
//}
//
//
//
//
//unsigned Baseball::FindRightNearest(std::vector<std::unique_ptr<Worm>> WormVector)
//{
//    float baseballX = hitPos.x;
//    float baseballY = hitPos.y;
//    unsigned IndexOfNearest = 100; //code for not found
//    float DistanceOfNearest = 9999;
//    for (int i=0;i<WormVector.size();i++)
//    {
//        sf::Vector2f WormPos = WormVector[i]->getPosition();
//        if (abs(WormPos.y - baseballY) > heigthDifference) { continue; }
//        float distance = WormPos.x - baseballX;
//        if ((distance < DistanceOfNearest))
//        {
//            IndexOfNearest = i;
//            DistanceOfNearest = distance;
//        }
//    }
//    if (DistanceOfNearest > getRange()) { return 100; }
//    return IndexOfNearest;
//}
//
//void Baseball::rightHit(std::vector<std::unique_ptr<Worm>> WormVector)
//{
//    unsigned indexOfNearest = FindRightNearest(WormVector);
//    if (indexOfNearest == 100) { return; }
//    WormVector[indexOfNearest]->TakeDamage(damage);
//    WormVector[indexOfNearest]->putVelocity(recoil, recoil);
//}
//
//void Baseball::Hit(HitDirection direction, std::vector<std::unique_ptr<Worm>> WormVector)
//{
//    if (direction == HitDirection::Left) { leftHit(WormVector); }
//    else if (direction == HitDirection::Right) { rightHit(WormVector); }
//    else { throw std::invalid_argument("Given direction is incorrect"); }
//}