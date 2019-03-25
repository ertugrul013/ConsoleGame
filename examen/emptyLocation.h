#pragma once

#include <string>
#include "../headerFiles/Location.h"

class emptyLocation : public Location
{
public:
	emptyLocation();
	emptyLocation(std::string a_Name);
	emptyLocation(const emptyLocation& a_emptyLocation);

	~emptyLocation();

	emptyLocation& operator=(const emptyLocation& rhs);

	std::string Description() const;
};