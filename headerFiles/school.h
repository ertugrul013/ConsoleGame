#pragma once

#include <string>
#include "Location.h"

class school : public Location
{
public:
	school();
	school(std::string a_Name);
	school(const school& a_school);

	~school();

	school& operator=(const school& rhs);

	std::string Description() const;
};