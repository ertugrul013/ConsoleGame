#pragma once

#include <string>
#include "Object.h"

class Diamond : public Object
{
public:
	Diamond();
	Diamond(std::string a_Name, bool a_IsAcquirable, int a_Value);
	Diamond(const Diamond& a_Diamond);

	~Diamond();

	Diamond& operator=(const Diamond& rhs);
	
	std::string Description() const;

	int GetValue() const;

private:
	int m_Value;
};

inline int Diamond::GetValue() const
{
	return m_Value;
}