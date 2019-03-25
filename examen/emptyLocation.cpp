#include "emptyLocation.h"

emptyLocation::emptyLocation() :
	Location()
{}

emptyLocation::emptyLocation(std::string a_Name) :
	Location(a_Name)
{}

emptyLocation::emptyLocation(const emptyLocation& a_emptyLocation) :
	Location(a_emptyLocation)
{}

emptyLocation::~emptyLocation()
{}

emptyLocation& emptyLocation::operator=(const emptyLocation& rhs)
{
	if (this == &rhs)
	{
		return *this;
	}

	Location::operator=(rhs);

	return *this;
}

std::string emptyLocation::Description() const
{
	std::string descr = "There is nothing here.";
	return descr;
}