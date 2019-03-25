#include "../headerFiles/Forrest.h"

Forrest::Forrest()
	:	Location()
{}

Forrest::Forrest(std::string a_Name)
	:	Location(a_Name)
{}

Forrest::Forrest(const Forrest& a_Forrest)
	:	Location(a_Forrest)
{}

Forrest::~Forrest()
{}

Forrest& Forrest::operator=(const Forrest& rhs)
{
	if (this == &rhs)
		return *this;

	Location::operator=(rhs);

	return *this;
}

std::string Forrest::Description() const
{
	std::string descr = "You are standing in a forrest.";
	return descr;
}