#include <memory>
#include "box2d.h"
#include <SFML/System.hpp>
#include <vector>

using std::vector;

class DynamicModel
{
public:
    DynamicModel(b2World& w, float x, float y, b2Vec2 vertices[], int numberOfVertices);        // sizeof(vertices)/sizeof(b2Vec2) = ilosc elementow
    b2Vec2 getPosition() const;
    float getAngle() const;
    b2Fixture* getFixture(int idx) const;
    const b2Shape* getShape(int idx);
    float getRotationSpeed() const;

    void setNewPosition(const b2Vec2&, float);
    void transform(const b2Vec2&);
    void setRotationSpeed(float);
    void putVelocity(const b2Vec2);
    void putForceToCenter(const b2Vec2);


protected:
    b2Body* body;

    void addFixture(const b2FixtureDef*);

    friend class Spring;
};


////////////////////////////////////////////////////
//Worm
////////////////////////////////////////////////////


//Worm dziedziczy po dynamic object
//class Worm  : public DynamicModel
//{
//unsigned hp
//public:
//    Worm(b2World& world, float new_x, float new_y);
//    //const b2Vec2* getVertices();
//
//    void addWeapon();
//
//    void jump();
//    unsigned GetHP() const {return hp;}
//    void TakeDamage(unsigned damage) {hp -= damage}
//
//
//protected:
//    b2PolygonShape shapePolygon;
//    b2FixtureDef fixtureDef;
//
//    bool isOnGround();
//};


class Weapon : public DynamicModel
{

};
//class Grenade : public DynamicModel
//{
//public:
//    void GrenadeExplosion(vector<Worm>);
//    void putStartingVelocity(b2Body* body, float StartingX, float StartingY, sf::Vector2i mousePosition, float MouseTimeHold);
//    Grenade(b2World& world, float x, float y, sf::Vector2i mousePosition, float MouseTimeHold);
//};


class StaticModel
{

};


class Spring
{
public:
    Spring();
    void bind(b2World*, const DynamicModel*);
    void update(b2Vec2&);

protected:
    b2MouseJoint* mj;
};
