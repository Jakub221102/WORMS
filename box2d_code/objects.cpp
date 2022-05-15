#include "objects.h"

//konstruktor: tworzy jedynie cialo obiektu
DynamicObject::DynamicObject(b2World& world, float new_x, float new_y)
{
    def.type = b2_dynamicBody;
    def.position.Set(new_x, new_y);
    body = world.CreateBody(&def);
}

//mozna ustawic pozycje ciala w zupelnie nowym miejscu i pod innym katem
void DynamicObject::set_new_position(const b2Vec2& position, float angle)
{
    body->SetTransform(position, angle);
}


////////////////////////////////////////////////////
// WORM
////////////////////////////////////////////////////


/*Worm - DynamicObject, zdefiniowane shape, friction i density,
oraz wzgledne wierzcholki, przechowuje je po to bo nie ma prostej metody w box2d ktora by to robila, przynajmneij nie znalazlem, kiedys byla(?)*/
Worm::Worm(b2World& world, float new_x, float new_y) : DynamicObject(world, new_x, new_y)
{
    b2PolygonShape worm_shape;
    b2FixtureDef fixtureDef;

    vertices[0].x = -2;
    vertices[0].y = 2;

    vertices[1].x = 2;
    vertices[1].y = 2;

    vertices[2].x = 2;
    vertices[2].y = -2;

    vertices[3].x = -2;
    vertices[3].y = -2;

    worm_shape.Set(vertices, 4);
    fixtureDef.shape = &worm_shape;
    fixtureDef.density = 1.0f;
    fixtureDef.friction = 0.3f;
    body->CreateFixture(&fixtureDef);
}


//funkcja zwaraca fixture przypisany do ciala po indexie
const b2Fixture* Worm::getFixture(int idx = 0)
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
const b2Shape* Worm::getShape(int idx = 0)
{
    const b2Fixture* fixture = getFixture(idx);
    const b2Shape* shape = fixture->GetShape();
    return shape;
}


//doklada predkosc do ciala
void Worm::putVelocity(const b2Vec2 vec)
{
    body->SetLinearVelocity(vec);
}