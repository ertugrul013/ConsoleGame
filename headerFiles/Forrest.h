#pragma once

#include <string>
#include "Location.h"

class Forrest : public Location
{
public:
	Forrest();
	Forrest(std::string a_Name);
	Forrest(const Forrest& a_Forrest);

	~Forrest();

	Forrest& operator=(const Forrest& rhs);

	std::string Description() const;
};