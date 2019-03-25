#include "../headerFiles/Swamp.h"

Swamp::Swamp()
	:	Location()
{}

Swamp::Swamp(std::string a_Name)
	:	Location(a_Name)
{}

Swamp::Swamp(const Swamp& a_Swamp)
	:	Location(a_Swamp)
{}

Swamp::~Swamp()
{}

Swamp& Swamp::operator=(const Swamp& rhs)
{
	if (this == &rhs)
		return *this;

	Location::operator=(rhs);

	return *this;
}

std::string Swamp::Description() const
{
	std::string descr = "You are standing in a swamp.";
	return descr;
}