#include "worm.h"


void Worm::contactHandler()
{
	b2WorldManifold worldManifold;
	for (b2ContactEdge* edge = box2dModel->getContactList(); edge; edge = edge->next)
	{
		b2Contact* contact = edge->contact;
		contact->GetWorldManifold(&worldManifold);
		b2Body* bodyA = contact->GetFixtureA()->GetBody();
		b2Body* bodyB = contact->GetFixtureB()->GetBody();

		
		if (contact->IsTouching())
		{
			if (worldManifold.normal.y > 0)
			{
				if (bodyA->GetType() == b2_staticBody)
				{
					this->setJumpReady();
					if (worldManifold.normal.y > 0.8 && worldManifold.normal.y < 0.9)
					{
						//bodyB->SetLinearVelocity({ worldManifold.normal.x, -worldManifold.normal.y * 1000000 }, 1);
						//bodyB->SetFixedRotation(false);
						//bodyB->ApplyLinearImpulse({ 0, 1000 }, bodyB->GetPosition() + b2Vec2(10, 0), 1);
					}
				}
				else if (jumpReady == JumpState::noneLeft) {

					this->setHalfJump();
				}
			}

			if (bodyA->GetType() == b2_dynamicBody && bodyB->GetType() == b2_dynamicBody)
			{
				float massA = bodyA->GetMass();
				float massB = bodyB->GetMass();
				//std::cout << "MASS A:\t" << massA << std::endl;
				//std::cout << "MASS B:\t" << massB << std::endl;
				if ((bodyA->IsBullet() || bodyB->IsBullet()) && (massA == 4 || massB == 4)) //wstaw mase pocisku 
				{
					TakeDamage(10);
				}
			}
		}
	}
}


void Worm::bulletContactHandler()
{
	b2WorldManifold worldManifold;
	for (b2ContactEdge* edge = bullet->box2dModel->getContactList(); edge; edge = edge->next)
	{
		b2Contact* contact = edge->contact;
		contact->GetWorldManifold(&worldManifold);
		b2Body* bodyA = contact->GetFixtureA()->GetBody();
		b2Body* bodyB = contact->GetFixtureB()->GetBody();

		float mass = bodyB->GetMass();
		std::cout << "MASS BULLET:\t" << mass << std::endl;
		if (contact->IsTouching())
		{
			this->bullet->isLive = false;
		}
	}
}