#include "game_objects.h"

#define PI 3.14159265359f

float angleBoxToSfml(float angle)
{
	angle = -angle * 180.0f / PI;
	return angle;
}


Spring::Spring() : mj(nullptr)
{
}

void Spring::bind(float x, float y, b2World* world, const GR::DynamicObject* objB)
{

	b2BodyDef mouseBoxDef;
	mouseBoxDef.position.Set(1.0f, 1.0f);

	b2FixtureDef fix;

	b2PolygonShape mouseBox;
	mouseBox.SetAsBox(1.0f, 1.0f);
	fix.shape = &mouseBox;

	b2Body* ground = world->CreateBody(&mouseBoxDef);
	ground->CreateFixture(&fix);

	b2MouseJointDef mjd;

	mjd.bodyA = ground;
	mjd.bodyB = objB->box2dModel->body;

	b2Vec2 v(x, y);
	mjd.target = v;

	mjd.maxForce = 5000.0 * objB->box2dModel->body->GetMass();
	mjd.stiffness = 10000.0f;
	mjd.damping = 0.9f;

	mj = (b2MouseJoint*)world->CreateJoint(&mjd);

}


void Spring::update(float x, float y)
{
	if (mj != nullptr)
	{
		mj->SetTarget({ x, y });
	}
}
