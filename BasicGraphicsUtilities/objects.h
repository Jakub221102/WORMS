#pragma once
#include <memory>
# include "box2d.h"
# include <SFML/System.hpp>
#include <vector>
using std::vector;

class Model
{
protected:
    b2Body* body;

    void addFixture(const b2FixtureDef*);

public:
    b2Vec2 getPosition() const;
    float getAngle() const;
    b2Fixture* getFixture(int idx) const;
    const b2Shape* getShape(int idx);
    float getRotationSpeed() const;
    b2Vec2 getVelocity();
    b2World* getWorld();

    void setNewPosition(const b2Vec2&, float);
    void transform(const b2Vec2&);
    void setRotationSpeed(float);
    void putVelocity(const b2Vec2);
    void addVelocity(const b2Vec2);
    void putForceToCenter(const b2Vec2);
    void putForceToPoint(const b2Vec2, const b2Vec2);
    void putImpulseToCenter(const b2Vec2);
    void putImpulseToPoint(const b2Vec2, const b2Vec2);

    b2ContactEdge* getContactList();

};


class DynamicModel : public Model
{
protected:
    friend class Spring;

public:
    DynamicModel(b2World& w, float x, float y, b2Vec2 vertices[], int numberOfVertices, bool noRotation = false);        // sizeof(vertices)/sizeof(b2Vec2) = ilosc elementow


};

class StaticModel : Model
{
public:
    StaticModel(b2World& w, float x, float y, b2Vec2 vertices[], int numberOfVertices);
};





//class Grenade : public DynamicModel
//{
//public:
//    void GrenadeExplosion(vector<Worm>);
//    void putStartingVelocity(b2Body* body, float StartingX, float StartingY, sf::Vector2i mousePosition, float MouseTimeHold);
//    Grenade(b2World& world, float x, float y, sf::Vector2i mousePosition, float MouseTimeHold);
//};



class Spring
{
public:
    Spring();
    void bind(b2World*, const DynamicModel*);
    void update(b2Vec2&);

protected:
    b2MouseJoint* mj;
};
