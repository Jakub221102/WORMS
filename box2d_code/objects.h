#include <box2d.h>



class DynamicObject
{
public:
    DynamicObject(b2World&, float, float);
    void set_new_position(const b2Vec2&, float);
    b2Body* body;

private:
    b2BodyDef def;
};




////////////////////////////////////////////////////
// WORM
////////////////////////////////////////////////////


//worm dziedziczy po dynamic object
class Worm : public DynamicObject
{
public:
    b2Vec2 vertices[4];
    Worm(b2World& world, float new_x, float new_y);
    const b2Fixture* getFixture(int idx);
    const b2Shape* getShape(int idx);
    void putVelocity(b2Vec2);

};
