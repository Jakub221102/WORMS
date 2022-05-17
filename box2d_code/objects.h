#include <memory>
#include <box2d.h>



class DynamicObject
{
public:
    DynamicObject(b2World&, float, float);
    b2Vec2 getPosition() const;
    float getAngle() const;
    const void setNewPosition(const b2Vec2&, float);
    void putVelocity(b2Vec2);
    b2Body* body;

protected:
    b2BodyDef def;
};




////////////////////////////////////////////////////
//Polygon
////////////////////////////////////////////////////


//Polygon dziedziczy po dynamic object
class Polygon : public DynamicObject
{
public:
    Polygon(b2World& world, float new_x, float new_y, const b2Vec2* setVertices, int n_vertices);
    b2Fixture* getFixture(int idx) const;
    const b2Shape* getShape(int idx);
    const b2Vec2* getVertices();

protected:
    const int nVertices;
    const b2Vec2 *vertices;
};
