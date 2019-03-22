#pragma once

#include <string>
#include <vector>
#include "Location.h"
#include "Constants.h"

struct Position
{
public:
	int XPos;
	int Ypos;
};

struct Directions
{
public:
	int North;
	int East;
	int South;
	int West;
};

class Map
{
public:
	Map();
	Map(std::vector< std::vector<Location*> >& a_Map, int a_YStartPos, int a_XStartPos);
	Map(const Map& a_Map);

	~Map();

	Map& operator=(const Map& rhs);

	void AddLocation(Location& a_Loc, int a_YPos, int a_XPos);
	void Move(std::string a_Dir);
	void AllowedDirections();

	Location& GetLocation() const;
	int GetNorth() const;
	int GetEast() const;
	int GetSouth() const;
	int GetWest() const;

private:
	Position m_Pos;
	Directions m_Dir;
	std::vector< std::vector<Location*> > m_Map;
};

inline Location& Map::GetLocation() const
{
	return *m_Map[m_Pos.Ypos][m_Pos.XPos];
}

inline int Map::GetNorth() const
{
	return m_Dir.North;
}

inline int Map::GetEast() const
{
	return m_Dir.East;
}

inline int Map::GetSouth() const
{
	return m_Dir.South;
}

inline int Map::GetWest() const
{
	return m_Dir.West;
}