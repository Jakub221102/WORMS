//#include "dynamic_game_object.h"
//#include <vector>
//#include "box2d.h"
//#include <stdexcept>
//#include "static_animated_object.h"
//#include "worm.h"
//
//
//#ifndef WEAPONS
//#define WEAPONS
//
//
//
//class Grenade : public GR::DynamicObject
//{
//private:
//    float currentTime = 0;
//    float explosionTime = 3;
//    std::vector<Worm> WormVector;
//public:
//    void SetExplosionTime(float newTime) { explosionTime = newTime; }
//    float GetExplosionTime() const { return explosionTime; }
//
//    void IncCurrentTime(float deltaTime) { currentTime += deltaTime; }
//    float GetCurrentTime() const { return currentTime; }
//
//    void SaveWormVector(std::vector<Worm> NewWormVector) { WormVector = NewWormVector; }
//    std::vector<Worm> getWormVector() { return WormVector; }
//    void GrenadeExplosion()
//    {
//        sf::Vector2f position = getPosition();
//        const float posX = position.x;
//        const float posY = position.y;
//        //Distance scale is recoil ratio
//        float DistanceScale = 5;
//        //B³a¿ej help bo sie zesram
//        //for (int i=0; i < WormVector.size();i++)
//        //    {
//        //    Worm worm = getWormVector()[i];
//        //    sf::Vector2f wormPos = worm.getPosition();
//        //    float WormDistance = sqrt(pow(posX - wormPos.x, 2) + pow(posY - wormPos.y, 2));
//        //    if (WormDistance < DistanceScale * 6) { worm.TakeDamage(10); }
//        //    if (WormDistance < DistanceScale * 4) { worm.TakeDamage(10); }
//        //    if (WormDistance < DistanceScale * 2)
//        //    {
//        //        worm.TakeDamage(10);
//        //        sf::Vector2f wormPos = worm.getPosition();
//        //        sf::Vector2f RecoilVel((wormPos.x - posX) / 2, (wormPos.y - posY) / 2);
//        //        worm.putVelocity(RecoilVel);
//        //    }
//        //    if (WormDistance < DistanceScale * 1) { worm.TakeDamage(10); }
//        //}
//    }
//    void update();
//    void putStartingVelocity(sf::Vector2f mousePosition, float MouseTimeHold);
//
//    Grenade(b2World& world, const float& time, std::vector<std::pair<float, float>> vertices, std::string texture_path,
//        sf::Vector2f& startingPos, sf::Vector2f& mousePosition, float MouseTimeHold, std::vector<Worm> WormVector)
//        :GR::DynamicObject(world, time, vertices, texture_path), GR::StaticObject(time, vertices, texture_path)
//    {
//        const float circleSize = 1;
//        b2BodyDef def;
//        def.type = b2_dynamicBody;
//        def.position.Set(startingPos.x, startingPos.y);
//        b2Body* body = world.CreateBody(&def);
//        b2CircleShape circleShape;
//        circleShape.m_radius = circleSize;
//        body->CreateFixture(&circleShape, 1);
//
//        StaticObject::setPosition(startingPos.x, startingPos.y);
//        putStartingVelocity(mousePosition, MouseTimeHold);
//        SaveWormVector(WormVector);
//    }
//
//};
//
//enum class HitDirection
//{
//    Left, Right
//};
//
////Baseball hits nearest worm in chosen direction, friendlyfire on
//class Baseball : public GR::StaticAnimatedObject
//{
//private:
//    const unsigned heigthDifference = 10;
//    const unsigned damage = 50;
//    const unsigned range = 30;
//    std::vector<Worm> WormVector;
//public:
//    void SaveWormVector(std::vector<Worm> NewWormVector) { WormVector = NewWormVector; }
//    std::vector<Worm> getWormVector() { return WormVector; }
//
//    unsigned getDamage() const { return damage; }
//    unsigned getRange() const { return range; }
//    unsigned getHeigthDifference() const { return heigthDifference; }
//
//    void leftHit(sf::Vector2f hitPos);
//    void rightHit(sf::Vector2f hitPos);
//
//    unsigned FindLeftNearest(sf::Vector2f hitPos);
//    unsigned FindRightNearest(sf::Vector2f hitPos);
//
//    Baseball(const float& time, std::vector<std::pair<float, float>> vertices, const std::string& texture_path, sf::Vector2f hitPos, HitDirection direction)
//        : GR::StaticAnimatedObject(time, vertices, texture_path), GR::StaticObject(time, vertices, texture_path)
//    {
//        //addAnimation(????);
//        void SaveWormVector(std::vector<Worm> NewWormVector) { WormVector = NewWormVector; }
//        if (direction == HitDirection::Left) { leftHit(hitPos); }
//        else if (direction == HitDirection::Right) { rightHit(hitPos); }
//        else { throw std::invalid_argument("Given direction is incorrect"); }
//    }
//};
//
//
//
//#endif