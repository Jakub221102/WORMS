#pragma once
#include "box2d.h"


class ContactListener : public b2ContactListener
{
public:

	void BeginContact(b2Contact* contact)
	{ /* handle begin event */
		
	}

	void EndContact(b2Contact* contact)
	{ /* handle end event */
	}

	void PreSolve(b2Contact* contact, const b2Manifold* oldManifold)
	{ 
		b2WorldManifold worldManifold;
		contact->GetWorldManifold(&worldManifold);
		
		//if (worldManifold.normal.y < 1.0f || worldManifold.normal.y < -1.0f)
		//{
			//contact->GetFixtureA()->GetBody()->ApplyForceToCenter({ 0, 100000000 }, 1);
			//b2Body* bodyB = contact->GetFixtureB()->GetBody();
			//bodyB->ApplyForceToCenter({ 0, 1000000 }, 1);
			//contact->SetEnabled(false);
		//}
	}

	void PostSolve(b2Contact* contact, const b2ContactImpulse* impulse)
	{ /* handle post-solve event */
	}
};