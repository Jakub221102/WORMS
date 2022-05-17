#include "objects.h"

//konstruktor: tworzy jedynie cialo obiektu
DynamicObject::DynamicObject(b2World& world, float new_x, float new_y)
{
    def.type = b2_dynamicBody;
    def.position.Set(new_x, new_y);
    body = world.CreateBody(&def);
}


b2Vec2 DynamicObject::getPosition() const
{
    return body->GetPosition();
}


float DynamicObject::getAngle() const
{
    return body->GetAngle();
}


//mozna ustawic pozycje ciala w zupelnie nowym miejscu i pod innym katem
const void DynamicObject::setNewPosition(const b2Vec2& position, float angle)
{
    body->SetTransform(position, angle);
}

//doklada predkosc do ciala
void DynamicObject::putVelocity(const b2Vec2 vec)
{
    body->SetLinearVelocity(vec);
}



////////////////////////////////////////////////////
// Polygon
////////////////////////////////////////////////////


/*Polygon - DynamicObject, zdefiniowane shape, friction i density,
oraz wzgledne wierzcholki, przechowuje je po to bo nie ma prostej metody w box2d ktora by to robila, przynajmneij nie znalazlem, kiedys byla(?)*/
Polygon::Polygon(b2World& world, float new_x, float new_y, const b2Vec2* setVertices, int n_vertices) : DynamicObject(world, new_x, new_y), vertices(setVertices), nVertices(n_vertices)
{
    b2PolygonShape shapePolygon;
    b2FixtureDef fixtureDef;
    
    shapePolygon.Set(vertices, n_vertices);
    
    fixtureDef.shape = &shapePolygon;
    fixtureDef.density = 1.0f;
    fixtureDef.friction = 0.3f;
    body->CreateFixture(&fixtureDef);
}


//czy moge robic kopie i zwracac wskaznik na te kopie??
const b2Vec2* Polygon::getVertices()
{
    return vertices;
}


//funkcja zwaraca fixture przypisany do ciala po indexie
b2Fixture* Polygon::getFixture(int idx = 0) const
{
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
const b2Shape* Polygon::getShape(int idx = 0)
{
    const b2Fixture* fixture = getFixture(idx);
    const b2Shape* shape = fixture->GetShape();
    return shape;
}

