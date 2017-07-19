#pragma once

#include <array>

#include "IProperty.h"
#include "utils.h"


class INameble abstract : public IProperty
{
public:
	enum Type
	{
		name, description
	};
	virtual wstring getName(Type t = Type::name) = 0;
	virtual void setName(wstring&& nm, Type t = Type::name) = 0;
	virtual wchar_t getChar() = 0;
};

class Name
{
public:
	array<wstring, 2> name_descr;
	wchar_t ch;
};


