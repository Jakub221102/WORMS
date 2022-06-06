//#include "dynamic_game_object.h"
//#include <vector>
//#include "box2d.h"
//#include <stdexcept>
//#include "static_animated_object.h"
//#include "worm.h"
//
//
//
//
//class Grenade : public GR::DynamicObject
//{
//private:
//    const float recoilRatio = 0.5;
//    float currentTime = 0;
//    const float explosionTime = 3;
//    std::vector<Worm> WormVector;
//public:
//    float GetExplosionTime() const { return explosionTime; }
//    void IncCurrentTime(float deltaTime) { currentTime += deltaTime; }
//    float GetCurrentTime() const { return currentTime; }
//
//    std::vector<Worm> getWormVector() { return WormVector; }
//    void GrenadeExplosion();
//
//    void update();
//    void putStartingVelocity(sf::Vector2f mousePosition, float MouseTimeHold);
//
//    Grenade(b2World& world, const float& time, std::string texture_path, sf::Vector2f& startingPos, sf::Vector2f& mousePosition, float MouseTimeHold, std::vector<Worm> GameWormVector)
//        :GR::DynamicObject(world, time, { {0.66, 1}, {1, 0.66}, {1, 0.33}, {0.66, 0}, {0.33, 0}, {0, 0.33}, {0, 0.66}, {0.33, 1} }, texture_path),
//        GR::StaticObject(time, { {0.66, 1}, {1, 0.66}, {1, 0.33}, {0.66, 0}, {0.33, 0}, {0, 0.33}, {0, 0.66}, {0.33, 1} }, texture_path)
//    {
//      WormVector = GameWormVector;
//        putStartingVelocity(mousePosition, MouseTimeHold);
//    }
//
//};
//
////////==================================================================================
////////==================================================================================
////////==================================================================================
////////==================================================================================
////////==================================================================================
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
//    const float recoil = 5;
//    const unsigned heigthDifference = 10;
//    const unsigned damage = 50;
//    const unsigned range = 30;
//    sf::Vector2f hitPos = getPosition();
//    std::vector<Worm> WormVector;
//public:
//
//    unsigned getDamage() const { return damage; }
//    unsigned getRange() const { return range; }
//
//    void leftHit();
//    void rightHit();
//
//    unsigned FindLeftNearest();
//    unsigned FindRightNearest();
//
//    void Hit(HitDirection);
//
//    Baseball(const float& time, const std::string& texture_path, HitDirection direction, std::vector<Worm> GameWormVector)
//        : GR::StaticAnimatedObject(time, { {0,0},{0,1},{1,1},{1,0} }, texture_path), GR::StaticObject(time, { {0,0},{0,1},{1,1},{1,0} }, texture_path)
//    {
//        WormVector = GameWormVector;
//        Hit(direction);
//    }
//};
//
//
//
