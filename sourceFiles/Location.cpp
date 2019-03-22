#include "Location.h"

Location::Location()
	:	m_Name("Default"),
		m_HasEnemy(false),
		m_Objects(NULL)
{}

Location::Location(std::string a_Name)
	:	m_Name(a_Name),
		m_HasEnemy(false),
		m_Objects(NULL)
{}

Location::Location(const Location& a_Loc)
	:	m_Name(a_Loc.m_Name),
		m_HasEnemy(a_Loc.m_HasEnemy),
		m_Objects(a_Loc.m_Objects)
{}

Location::~Location()
{}

Location& Location::operator=(const Location& rhs)
{
	if (this == &rhs)
		return *this;

	m_Name = rhs.m_Name;
	m_HasEnemy = rhs.m_HasEnemy;
	m_Objects = rhs.m_Objects;

	return *this;
}

bool Location::CheckForItems()
{

	return !(m_Objects.empty());
}