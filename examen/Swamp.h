#pragma once

#include <string>
#include "Location.h"

class Swamp : public Location
{
public:
	Swamp();
	Swamp(std::string a_Name);
	Swamp(const Swamp& a_Swamp);

	~Swamp();

	Swamp& operator=(const Swamp& rhs);

	std::string Description() const;
};