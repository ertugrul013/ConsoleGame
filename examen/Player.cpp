#include "Player.h"

Player::Player()
	:	Actor(),
		m_Inventory(NULL)
{}

Player::Player(std::string a_Name, int a_MaxHealth)
	:	Actor(a_Name, a_MaxHealth),
		m_Inventory(NULL)
{}

Player::Player(const Player& a_Player)
	:	Actor(a_Player),
		m_Inventory(a_Player.m_Inventory)
{}

Player::~Player()
{}

Player& Player::operator=(const Player& rhs)
{
	if (this == &rhs)
		return *this;

	Actor::operator=(rhs);
	m_Inventory = rhs.m_Inventory;

	return *this;
}

bool Player::DropItem(std::string a_ItemName)
{
	bool found = false;
	for (unsigned int i = 0; i < m_Inventory.size(); i++)
	{
		if (m_Inventory[i]->GetName() == a_ItemName)
		{
			found = true;
			delete m_Inventory[i];
			m_Inventory[i] = NULL;
		}
	}
	if (found)
	{
		std::vector<Object*> temp;

		for (unsigned int i = 0; i < m_Inventory.size(); i++)
		{
			if (m_Inventory[i] != NULL)
			{
				temp.push_back(m_Inventory[i]);
				delete m_Inventory[i];
				m_Inventory[i] = NULL;
			}
		}

		m_Inventory.erase(m_Inventory.begin(), m_Inventory.end());
		m_Inventory = temp;
		return true;
	}
	else
		return false;
}

bool Player::HasObject(std::string a_ItemName)
{
	for (unsigned int i = 0; i < m_Inventory.size(); i++)
	{
		if (m_Inventory[i]->GetName() == a_ItemName)
			return true;
	}

	return false;
}

bool Player::PickupItem(Object* a_Item)
{
	if (!HasObject(a_Item->GetName()))
	{
		m_Inventory.push_back(a_Item);
		return true;
	}
	else
	{
		return false;
	}
}

void Player::TakeHit(int a_Dmg)
{
	if (m_Health - a_Dmg > 0)
	{
		m_Health -= a_Dmg;
	}
	else
	{
		m_Health = 0;
		m_IsAlive = false;
	}
}