#include "Cliff.h"

Cliff::Cliff()
	:	Location()
{}

Cliff::Cliff(std::string a_Name)
	:	Location(a_Name)
{}

Cliff::Cliff(const Cliff& a_Cliff)
	:	Location(a_Cliff)
{}

Cliff::~Cliff()
{}

Cliff& Cliff::operator=(const Cliff& rhs)
{
	if (this == &rhs)
		return *this;

	Location::operator=(rhs);

	return *this;
}

std::string Cliff::Description() const
{
	std::string descr = "You are standing on a high cliff.\n";
	descr += "This is a dead end. You can only go back.";

	return descr;
}