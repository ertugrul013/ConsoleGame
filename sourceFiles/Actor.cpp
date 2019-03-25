#include "../headerFiles/Actor.h"

Actor::Actor()
	:	m_Name("Default"),
		m_MaxHealth(100),
		m_Health(100),
		m_IsAlive(true)
{}

Actor::Actor(std::string a_Name, int a_MaxHealth)
	:	m_Name(a_Name),
		m_MaxHealth(a_MaxHealth),
		m_IsAlive(true)
{
	if (m_MaxHealth <= 0)
	{
		m_MaxHealth = 1;
	}

	m_Health = m_MaxHealth;
}

Actor::Actor(const Actor& a_Actor)
	:	m_Name(a_Actor.m_Name),
		m_MaxHealth(a_Actor.m_MaxHealth),
		m_Health(a_Actor.m_Health),
		m_IsAlive(a_Actor.m_IsAlive)
{}

Actor::~Actor()
{}

Actor& Actor::operator=(const Actor& rhs)
{
	if (this == &rhs)
		return *this;

	m_Name = rhs.m_Name;
	m_MaxHealth = rhs.m_MaxHealth;
	m_Health = rhs.m_Health;
	m_IsAlive = rhs.m_IsAlive;

	return *this;
}