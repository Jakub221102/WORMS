#include "objects.h"

//konstruktor: tworzy jedynie cialo obiektu
DynamicModel::DynamicModel(b2World& world, float new_x, float new_y, b2Vec2 vertices[], int numberOfVertices)
{
    b2BodyDef def;
    def.type = b2_dynamicBody;
    def.position.Set(new_x, new_y);
    body = world.CreateBody(&def);
    
    b2PolygonShape shapePolygon;
    shapePolygon.Set(vertices, numberOfVertices);
    body->CreateFixture(&shapePolygon, 1);
}


b2Vec2 DynamicModel::getPosition() const
{
    return body->GetPosition();
}


float DynamicModel::getAngle() const
{
    return body->GetAngle();
}

//funkcja zwaraca fixture przypisany do ciala po indexie
b2Fixture* DynamicModel::getFixture(int idx = 0) const
{
    //dopisac sprawdznaie czy wgl istniejee fixture o tym indexie
    int i = 0;
    for (b2Fixture* f = body->GetFixtureList(); f; f = f->GetNext())
    {
        if (i == idx)
        {
            return f;
        }
        i++;
    }
}

//zwraca shape obiekietu 
const b2Shape* DynamicModel::getShape(int idx = 0)
{
    //tez mozna dopisac sprawdzanie
    const b2Fixture* fixture = getFixture(idx);
    const b2Shape* shape = fixture->GetShape();
    return shape;
}



//mozna ustawic pozycje ciala w zupelnie nowym miejscu i pod innym katem
void DynamicModel::setNewPosition(const b2Vec2& position, float angle)
{
    body->SetTransform(position, angle);
}

//nadaje predkosc cialu
void DynamicModel::putVelocity(const b2Vec2 vec)
{
    body->SetLinearVelocity(vec);
}

void DynamicModel::putForceToCenter(const b2Vec2 vec)
{
    body->ApplyForceToCenter(vec, true);
}


void DynamicModel::addFixture(const b2FixtureDef* fix)
{  
    body->CreateFixture(fix);
}





////////////////////////////////////////////////////
// Worm
////////////////////////////////////////////////////


/*Worm - DynamicModel, zdefiniowane shape, friction i density,
oraz wzgledne wierzcholki, przechowuje je po to bo nie ma prostej metody w box2d ktora by to robila, przynajmneij nie znalazlem, kiedys byla(?)*/
//Worm::Worm(b2World& world, float new_x, float new_y) : DynamicModel(world, new_x, new_y)
//{
//    b2Vec2 vertices[4] = { b2Vec2(-2, 1), b2Vec2(-2, -1), b2Vec2(2, -1), b2Vec2(2, 1) };
//    shapePolygon.Set(vertices, 4);
//
//
//    fixtureDef.shape = &shapePolygon;
//    fixtureDef.density = 1.0f;
//    fixtureDef.friction = 0.3f;
//    body->CreateFixture(&fixtureDef);
//}

//void Worm::jump()
//{
//    this->putVelocity(b2Vec2(0, 10));
//}


//czy moge robic kopie i zwracac wskaznik na te kopie??
//const b2Vec2* Polygon::getVertices()
//{
//    return vertices;
//}





Spring::Spring() : mj(nullptr)
{
}

void Spring::bind(b2World* world, const DynamicModel* objB)
{
    b2BodyDef def;
    def.position.Set(1.0f, 1.0f);
    
    b2FixtureDef fix;

    b2PolygonShape shape;
    shape.SetAsBox(1.0f, 1.0f);
    fix.shape = &shape;

    b2Body* ground = world->CreateBody(&def);
    ground->CreateFixture(&fix);

    b2MouseJointDef mjd;

    mjd.bodyA = ground;
    mjd.bodyB = objB->body;

    b2Vec2 v(10, 10); 
    mjd.target = v;

    mjd.maxForce = 5000.0; //* objB->body->GetMass();
    mjd.stiffness = 10000.0f;
    mjd.damping = 0.9f;
    
    mj = (b2MouseJoint*)world->CreateJoint(&mjd);
       
}


void Spring::update(b2Vec2& vec)
{
    mj->SetTarget(vec);
}