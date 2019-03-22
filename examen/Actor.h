#pragma once

#include <string>

class Actor
{
public:
	Actor();
	Actor(std::string a_Name, int a_MaxHealth);
	Actor(const Actor& a_Actor);

	~Actor();

	virtual void TakeHit(int a_Damage) = 0;

	std::string GetName() const;
	int GetMaxHealth() const;
	int GetHealth() const;
	bool IsAlive() const;

protected:
	Actor& operator=(const Actor& rhs);

	std::string m_Name;
	int m_MaxHealth;
	int m_Health;
	bool m_IsAlive;
};

inline std::string Actor::GetName() const
{
	return m_Name;
}

inline int Actor::GetMaxHealth() const
{
	return m_MaxHealth;
}

inline int Actor::GetHealth() const
{
	return m_Health;
}

inline bool Actor::IsAlive() const
{
	return m_IsAlive;
}