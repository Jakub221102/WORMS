#include "worm.h"

void Worm::setJumpReady()
{
	jumpReady = JumpState::ready;
}


void Worm::contactHandler()
{
	b2WorldManifold worldManifold;
	for (b2ContactEdge* edge = box2dModel->getContactList(); edge; edge = edge->next)
	{
		b2Contact* contact = edge->contact;
		contact->GetWorldManifold(&worldManifold);
		b2Body* bodyA = contact->GetFixtureA()->GetBody();
		b2Body* bodyB = contact->GetFixtureB()->GetBody();
		
		//bodyA->ApplyLinearImpulseToCenter({ 0, 10000 }, 1);
		//bodyB->ApplyLinearImpulseToCenter({ 0, 10000 }, 1);
		if (bodyA->GetType() == b2_staticBody)
		{
			this->setJumpReady();
			std::cout << "A: STATIC" << std::endl;
			std::cout << "X: \t" << worldManifold.normal.x << std::endl;
			std::cout << "Y: \t" << worldManifold.normal.y << std::endl;
			bodyB->ApplyForceToCenter({ 0, -10 }, 1);
		}
		else if (bodyA->GetType() == b2_dynamicBody)
		{
			std::cout << "A: DYNAMIC" << std::endl;
		}
		
		//if (bodyB->GetType() == b2_staticBody)
		//{
		//	std::cout << "B: STATIC" << std::endl;
		//}
		//else if (bodyB->GetType() == b2_dynamicBody)
		//{
		//	std::cout << "B: DYNAMIC" << std::endl;
		//}

	}
}