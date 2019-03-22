#pragma once

#include <string>
#include <vector>

#include "Object.h"
#include "Actor.h"

class Player : public Actor
{
public:
	Player();
	Player(std::string a_Name, int a_MaxHealth);
	Player(const Player& a_Player);

	~Player();

	Player& operator=(const Player& rhs);

	bool DropItem(std::string a_ItemName);
	bool PickupItem(Object* a_Item);
	bool HasObject(std::string a_ItemName);
	void TakeHit(int a_Dmg);

	std::vector<Object*>& GetInventory();
private:
	std::vector<Object*> m_Inventory;
};

inline std::vector<Object*>& Player::GetInventory()
{
	return m_Inventory;
}