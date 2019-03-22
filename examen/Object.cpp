#include "Object.h"

Object::Object()
	: m_Name("Default"),
	m_Acquirable(true)
{}

Object::Object(std::string a_Name, bool a_Acquirable)
	: m_Name(a_Name),
	m_Acquirable(a_Acquirable)
{}

Object::Object(const Object& a_Object)
	: m_Name(a_Object.m_Name),
	m_Acquirable(a_Object.m_Acquirable)
{}

Object::~Object()
{}

Object& Object::operator=(const Object& rhs)
{
	if (this == &rhs)
		return *this;

	m_Name = rhs.m_Name;
	m_Acquirable = rhs.m_Acquirable;

	return *this;
}