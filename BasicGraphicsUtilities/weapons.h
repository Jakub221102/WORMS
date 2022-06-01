//#include <dynamic_game_object.h>
//#include <vector>
//#include <box2d.h>
//#include <stdexcept>
//
//class Grenade : public GR::DynamicObject
//{
//    private:wd
//        float currentTime = 0;
//        float explosionTime = 3;
//    public:
//        void SetExplosionTime(float newTime) { explosionTime = newTime; }
//        float GetExplosionTime() const { return explosionTime; }
//
//        void IncCurrentTime(float deltaTime) { currentTime += deltaTime; }
//        float GetCurrentTime() const { return currentTime; }
//
//        void GrenadeExplosion();
//        void update();
//        void putStartingVelocity(sf::Vector2i mousePosition, float MouseTimeHold);
//        Grenade(b2World& world, const float& time, std::vector<std::pair<float, float>> vertices, std::string texture_path,
//            sf::Vector2f& startingPos, sf::Vector2f& mousePosition, float MouseTimeHold);
//};
