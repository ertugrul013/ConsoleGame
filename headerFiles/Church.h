#pragma once

#include <string>
#include "Location.h"

class Church : public Location
{
public:
	Church();
	Church(std::string a_Name);
	Church(const Church& a_Church);

	~Church();

	Church& operator=(const Church& rhs);

	std::string Description() const;
};