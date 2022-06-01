#pragma once

#include "../BasicGraphicsUtilities/dynamic_game_object.h"

float angleBoxToSfml(float angle);

class Spring
{
protected:
	b2MouseJoint* mj;
public:
	Spring();
	void bind(float x, float y, b2World*, const GR::DynamicObject*);
	void update(float x, float y);

};

class Worm : 