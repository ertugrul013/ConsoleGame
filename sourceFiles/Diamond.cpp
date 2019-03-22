#include "Diamond.h"

Diamond::Diamond()
	:	Object(),
		m_Value(50)
{}

Diamond::Diamond(std::string a_Name, bool a_IsAcquirable, int a_Value)
	:	Object(a_Name, a_IsAcquirable),
		m_Value(a_Value)
{}

Diamond::Diamond(const Diamond& a_Diamond)
	:	Object(a_Diamond),
		m_Value(a_Diamond.m_Value)
{}

Diamond::~Diamond()
{}

Diamond& Diamond::operator=(const Diamond& rhs)
{
	if (this == &rhs)
		return *this;

	Object::operator=(rhs);
	m_Value = rhs.m_Value;

	return *this;
}

std::string Diamond::Description() const
{
	std::string descr = "This is a really beautiful diamond!";

	return descr;
}