#include "../headerFiles/school.h"

school::school() :
	Location()
{}

school::school(std::string a_Name) :
	Location(a_Name)
{}

school::school(const school& a_school) :
	Location(a_school)
{}

school::~school()
{}

school& school::operator=(const school& rhs)
{
	if (this == &rhs)
	{
		return *this;
	}

	Location::operator=(rhs);

	return *this;
}

std::string school::Description() const
{
	std::string descr = "You have enterd a school. You see someone waving to you.Do you go to him or go back.";
	return descr;
}
