#include "objects.h"
#include <cmath>
#include <stdexcept>



b2Vec2 Model::getPosition() const
{
    return body->GetPosition();
}


float Model::getAngle() const
{
    return body->GetAngle();
}


float Model::getRotationSpeed() const
{
    return body->GetAngularVelocity();
}

//funkcja zwaraca fixture przypisany do ciala po indexie
b2Fixture* Model::getFixture(int idx = 0) const
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
const b2Shape* Model::getShape(int idx = 0)
{
    //tez mozna dopisac sprawdzanie
    const b2Fixture* fixture = getFixture(idx);
    const b2Shape* shape = fixture->GetShape();
    return shape;
}



//mozna ustawic pozycje ciala w zupelnie nowym miejscu i pod innym katem
void Model::setNewPosition(const b2Vec2& position, float angle)
{
    body->SetTransform(position, angle);
}

void Model::transform(const b2Vec2& newPosition)
{
    b2Vec2 pos = getPosition();
    setNewPosition(pos + newPosition, getAngle());
}

void Model::setRotationSpeed(float speed)
{
    body->SetAngularVelocity(speed);
}


//nadaje predkosc cialu
void Model::putVelocity(const b2Vec2 vec)
{
    body->SetLinearVelocity(vec);
}

void Model::putForceToCenter(const b2Vec2 vec)
{
    body->ApplyForceToCenter(vec, true);
}


void Model::addFixture(const b2FixtureDef* fix)
{
    body->CreateFixture(fix);
}



//konstruktor: tworzy jedynie cialo obiektu
DynamicModel::DynamicModel(b2World& world, float new_x, float new_y, b2Vec2 vertices[], int numberOfVertices) : Model()
{
    b2BodyDef def;
    def.type = b2_dynamicBody;
    def.position.Set(new_x, new_y);
    body = world.CreateBody(&def);

    b2PolygonShape polygonShape;
    polygonShape.Set(vertices, numberOfVertices);
    body->CreateFixture(&polygonShape, 1);

}

StaticModel::StaticModel(b2World& world, float new_x, float new_y, b2Vec2 vertices[], int numberOfVertices)
{
    b2BodyDef def;
    def.type = b2_staticBody;
    def.position.Set(new_x, new_y);
    body = world.CreateBody(&def);

    b2ChainShape chainShape;
    chainShape.CreateLoop(vertices, numberOfVertices);
    body->CreateFixture(&chainShape, 1);
}


//towrzenie samego ksztalu ciala w klasie sfml albo przekazywanie samej definicji ciala



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


//Grenade::Grenade(b2World& world, float x, float y, sf::Vector2i mousePosition, float MouseTimeHold)
//{
//    const float circleSize = 1;
//    b2BodyDef def;
//    def.type = b2_dynamicBody;
//    def.position.Set(x, y);
//    body = world.CreateBody(&def);
//    b2CircleShape circleShape;
//    circleShape.m_radius= circleSize;
//    body->CreateFixture(&circleShape, 1);
//    putStartingVelocity(body, x, y, sf::Vector2i mousePosition, MouseTimeHold);
//
//}
//Sets startin velocity to grenade(based on worm position, mouse clicked position and time of clicking)

//void Grenade::putStartingVelocity(b2Body* body, float StartingX, float StartingY, sf::Vector2i mousePosition, float MouseTimeHold)
//{
//    if (MouseTimeHold < 0) { throw std::invalid_argument("Given time is incorrect"); }
//    if (MouseTimeHold > 1.5) { MouseTimeHold = 1.5; }
//    float maxStartingVelLen = 10;
//    float maxHoldingTime = 1.5;
//
//    float mouseClickedY = mousePosition.y;
//    float mouseClickedX = mousePosition.x;
//
//    float DistanceX = mouseClickedX - StartingX;
//    float DistanceY = mouseClickedY - StartingY;
//
//    float ClickedVecLen = sqrt(pow(DistanceX, 2) + pow(DistanceY, 2));
//
//    float VelY = (maxStartingVelLen * DistanceY) / ClickedVecLen;
//    float VelX = (maxStartingVelLen * DistanceX) / ClickedVecLen;
//
//    b2Vec2 StartingVelVec;
//    StartingVelVec.x = (VelX * MouseTimeHold) / maxHoldingTime;
//    StartingVelVec.y = (VelY * MouseTimeHold) / maxHoldingTime;
//    body->SetLinearVelocity(StartingVelVec);
//}
//
//void Grenade::GrenadeExplosion(vector<Worm> WormList)
//{
//    b2Vec2 position = getPosition();
//    float posX = position.x;
//    float posY = position.y;
//    float DistanceScale = 5;
//    for (const auto& Worm : WormList)
//    {
//        b2Vec2 wormPos = Worm.getPosition();
//        float WormDistance = sqrt(pow(posX - wormPos.x, 2) + pow(posY - wormPos.y, 2));
//        if (WormDistance < DistanceScale * 6) { Worm.TakeDamage(10); }
//        if (WormDistance < DistanceScale * 4) { Worm.TakeDamage(10); }
//        if (WormDistance < DistanceScale * 2)
//        {
//            Worm.TakeDamage(10);
//            //to sie ulepszy pzdr600
//            b2Vec2 RecoilVel((wormPos.x - posX)/2, 0);
//            Worm.putVelocity(RecoilVel);
//        }
//        if (WormDistance < DistanceScale * 1) { Worm.TakeDamage(10); }
//    }
//}