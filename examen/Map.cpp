#include "Map.h"

Map::Map()
{
	m_Pos.XPos = 0;
	m_Pos.Ypos = 0;
	Directions dir = { 0, 0, 0, 0 };
	m_Dir = dir;
	std::vector< std::vector<Location*> > a_Map(4, std::vector<Location*>(4));
	m_Map = a_Map;
	
}

Map::Map(std::vector< std::vector<Location*> >& a_Map, int a_YStartPos, int a_XStartPos)
	:	m_Map(a_Map)
{
	Directions dir = { 0, 0, 0, 0 };
	m_Dir = dir;

	if ((a_XStartPos >= 0 && a_XStartPos < MAPWIDTH) && (a_YStartPos >= 0 && a_YStartPos < MAPHEIGHT))
	{
		m_Pos.XPos = a_XStartPos;
		m_Pos.Ypos = a_YStartPos;
	}
	else
	{
		m_Pos.XPos = 0;
		m_Pos.Ypos = 0;
	}
}

Map::Map(const Map& a_Map)
	:	m_Map(a_Map.m_Map),
		m_Pos(a_Map.m_Pos),
		m_Dir(a_Map.m_Dir)
{}

Map::~Map()
{}

Map& Map::operator=(const Map& rhs)
{
	if (this == &rhs)
		return *this;

	m_Pos = rhs.m_Pos;
	m_Dir = rhs.m_Dir;
	m_Map = rhs.m_Map;

	return *this;
}

void Map::AddLocation(Location& a_Loc, int a_YPos, int a_XPos)
{
	if ((a_XPos >= 0 && a_XPos < MAPWIDTH) && (a_YPos >= 0 && a_YPos < MAPHEIGHT))
	{
		m_Map[a_YPos][a_XPos] = &a_Loc;
	}
}

void Map::Move(std::string a_Dir)
{
	if (a_Dir == "Go North")
		m_Pos.Ypos += 1;
	if (a_Dir == "Go East")
		m_Pos.XPos += 1;
	if (a_Dir == "Go South")
		m_Pos.Ypos -= 1;
	if (a_Dir == "Go West")
		m_Pos.XPos -= 1;
}

void Map::AllowedDirections()
{
	m_Dir = { 1, 1, 1, 1 };

	if (m_Pos.Ypos + 1 >= MAPHEIGHT)
		m_Dir.North = -1;
	else if (m_Map[m_Pos.Ypos + 1][m_Pos.XPos] == NULL)
		m_Dir.North = -1;

	if (m_Pos.Ypos - 1 < 0)
		m_Dir.South = -1;
	else if (m_Map[m_Pos.Ypos - 1][m_Pos.XPos] == NULL)
		m_Dir.South = -1;

	if (m_Pos.XPos + 1 >= MAPWIDTH)
		m_Dir.East = -1;
	else if (m_Map[m_Pos.Ypos][m_Pos.XPos + 1] == NULL)
		m_Dir.East = -1;

	if (m_Pos.XPos - 1 < 0)
		m_Dir.West = -1;
	else if (m_Map[m_Pos.Ypos][m_Pos.XPos - 1] == NULL)
		m_Dir.West = -1;
}