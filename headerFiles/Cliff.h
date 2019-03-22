#pragma once

#include <string>
#include "Location.h"

class Cliff : public Location
{
public:
	Cliff();
	Cliff(std::string a_Name);
	Cliff(const Cliff& a_Cliff);

	~Cliff();

	Cliff& operator=(const Cliff& rhs);

	std::string Description() const;
};