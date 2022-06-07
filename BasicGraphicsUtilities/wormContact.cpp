#include "worm.h"

void Worm::setJumpReady()
{
	jumpReady = JumpState::ready;
	jumpCooldown = 0;
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
			if (worldManifold.normal.y > 0 && contact->IsTouching())
			{
				//bodyB->ApplyForceToCenter({ -worldManifold.normal.x * 100000, -worldManifold.normal.y * 100000 }, 1);
				this->setJumpReady();
				if (worldManifold.normal.y > 0.8 && worldManifold.normal.y < 0.9)
				{
					//bodyB->SetLinearVelocity({ worldManifold.normal.x, -worldManifold.normal.y * 1000000 }, 1);
					//bodyB->SetFixedRotation(false);
					//bodyB->ApplyLinearImpulse({ 0, 1000 }, bodyB->GetPosition() + b2Vec2(10, 0), 1);
				}
			}
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