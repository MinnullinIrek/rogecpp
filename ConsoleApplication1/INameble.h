#pragma once
#include "IProperty.h"

class INameble abstract : public IProperty
{
public:
	enum Type
	{
		name, description
	};
	virtual wstring getName(Type t = Type::name) = 0;
	virtual void setName(wstring&& nm, Type t = Type::name) = 0;
};

