#include "Church.h"

Church::Church()
	:	Location()
{}

Church::Church(std::string a_Name)
	:	Location(a_Name)
{}

Church::Church(const Church& a_Church)
	:	Location(a_Church)
{}

Church::~Church()
{}

Church& Church::operator=(const Church& rhs)
{
	if (this == &rhs)
		return *this;

	Location::operator=(rhs);

	return *this;
}

std::string Church::Description() const
{
	std::string descr = "You are standing in front of a church.";
	return descr;
}