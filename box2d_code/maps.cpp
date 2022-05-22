#include "maps.h"
#include <iostream>


void GameMap::SetPlainMap(b2World &world, unsigned Teams)
{
	b2BodyDef PlainGroundDef;
	PlainGroundDef.position.Set(500.0f, 300.0f);
	b2Body* PlainGround = world.CreateBody(&PlainGroundDef);
	b2PolygonShape groundShape;
	groundShape.SetAsBox(175.0f, 25.0f);
	PlainGround->CreateFixture(&groundShape, 1.0f);
	SetMapLeftBorder(325.0f);
	SetMapRightBorder(675.0f);
	SetWormMinHeigth(275.0f);
	float WormDistance = 17.5f;
	std::vector<std::vector<std::vector<float>>> TempTeamsSpawnPlaces = { {{}} };
	for (int i=1; i <= Teams; i++)
	{
		TempTeamsSpawnPlaces[i-1] =
			{
				{325.0f + i * WormDistance, 326.0f},
				{412.5f + i * WormDistance, 326.0f},
				{500.0f + i * WormDistance, 326.0f},
				{587.5f + i * WormDistance, 326.0f}
			};
	}
	SetTeamsSpawnPlaces(TempTeamsSpawnPlaces);
}


void GameMap::SetPyramidasMap(b2World& world, unsigned Teams)
{
	std::cout << "Polsh tabak";
}

void GameMap::SetHillsMap(b2World& world, unsigned Teams)
{
	std::cout << "redbvvl";
}
