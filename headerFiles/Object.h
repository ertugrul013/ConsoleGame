#pragma once

#include <string>

class Object
{
public:
	Object();
	Object(std::string a_Name, bool a_Acquirable);
	Object(const Object& a_Object);

	virtual ~Object();

	Object& operator=(const Object& rhs);

	virtual std::string Description() const = 0;

	bool IsAcquirable() const;
	void SetIsAcquirable(bool a_Acquirable);
	std::string GetName() const;

protected:
	std::string m_Name;
	bool m_Acquirable;
};

inline bool Object::IsAcquirable() const
{
	return m_Acquirable;
}

inline void Object::SetIsAcquirable(bool a_Acquirable)
{
	m_Acquirable = a_Acquirable;
}

inline std::string Object::GetName() const
{
	return m_Name;
}