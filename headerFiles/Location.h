#pragma once

#include <string>
#include <vector>

#include "Object.h"

class Location
{
public:
	Location();
	Location(std::string a_Name);
	Location(const Location& a_Loc);

	virtual ~Location();

	virtual std::string Description() const = 0;

	void AddObject(Object* a_Object);
	bool CheckForItems();

	std::string GetName() const;
	bool HasEnemy() const;
	std::vector<Object*> GetObjects() const;

protected:
	Location& operator=(const Location& rhs);
	std::string m_Name;
	bool m_HasEnemy;
	std::vector<Object*> m_Objects;
};

inline void Location::AddObject(Object* a_Object)
{
	m_Objects.push_back(a_Object);
}

inline std::string Location::GetName() const
{
	return m_Name;
}

inline bool Location::HasEnemy() const
{
	return m_HasEnemy;
}

inline std::vector<Object*> Location::GetObjects() const
{
	return m_Objects;
}