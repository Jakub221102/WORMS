# include "box2d.h"
# include <vector>
# include <stdexcept>

#ifndef MAP_CLASS
#define MAP_CLASS

enum class Map
{
	pyramids, plain, hills
};

class GameMap
{
private:
	float WormMinHeigth = 0;
	std::vector<std::vector<std::vector<float>>> TeamsSpawnPlaces = { {{}} };

	float MapLeftBorder = 0;
	float MapRightBorder = 0;

public:
	float GetMapLeftBorder() const { return MapLeftBorder; }
	float GetMapRightBorder() const { return MapRightBorder; }
	void SetMapRightBorder(float NewRightBorder) { MapRightBorder = NewRightBorder; }
	void SetMapLeftBorder(float NewLeftBorder) { MapLeftBorder = NewLeftBorder; }

	void SetWormMinHeigth(float NewHeight) { WormMinHeigth = NewHeight; }

	void SetTeamsSpawnPlaces(std::vector<std::vector<std::vector<float>>> NewTeamASpawnPlaces)
	{TeamsSpawnPlaces = NewTeamASpawnPlaces;}

	void SetPyramidasMap(b2World& world, unsigned Teams);
	void SetPlainMap(b2World& world, unsigned Teams);
	void SetHillsMap(b2World& world, unsigned Teams);

	float GetWormMinHeight() const { return WormMinHeigth; }

	std::vector<std::vector<std::vector<float>>> GetTeamsSpawnPlaces() const { return TeamsSpawnPlaces; }

	GameMap(b2World& world, Map SelectedMap, unsigned Teams)
	{
		if ((Teams == 2) || (Teams == 3) || (Teams == 4))
		{
			switch (SelectedMap)
			{
			case Map::pyramids: {SetPyramidasMap(world, Teams); } break;
			case Map::plain: {SetPlainMap(world, Teams); } break;
			case Map::hills: {SetHillsMap(world, Teams); } break;
			default: {throw std::invalid_argument("Invalid map given"); } break;
			}
		}
		else { throw std::invalid_argument("Invalid teams number"); }
	}
};




#endif