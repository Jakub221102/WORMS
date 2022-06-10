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

			if (bodyA->GetType() == b2_dynamicBody && bodyB->GetType() == b2_dynamicBody && dmgCooldown == 0)
			{
				float massA = bodyA->GetMass();
				float massB = bodyB->GetMass();
				//std::cout << "MASS A:\t" << massA << std::endl;
				//std::cout << "MASS B:\t" << massB << std::endl;
				if (bodyA->IsBullet() || bodyB->IsBullet())
				{
					if (massA == 4 || massB == 4) //wstaw mase pocisku 
					{
						TakeDamage(10);
					}
					else if (massA == 16 || massB == 16)
					{
						TakeDamage(20);
						if (worldManifold.normal.x > 0)
						{
							this->putVelocity({ -10, 40 });
						}
						else
						{
							this->putVelocity({ 10, 40 });
						}
						dmgCooldown = 4;
					}
					else if ((massA > 64 && massA < 65) || (massB > 64 && massB < 65))
					{
						TakeDamage(50);
						if (worldManifold.normal.x > 0)
						{
							this->putVelocity({ -40, 50 });
						}
						else
						{
							this->putVelocity({ 40, 50 });
						}
						dmgCooldown = 4;
					}
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
			if (this->bullet->type == WeaponType::granade)
			{
				//std::cout << "GRANADE" << mass << std::endl;

			}
			this->bullet->isLive = false;
		}
	}
}