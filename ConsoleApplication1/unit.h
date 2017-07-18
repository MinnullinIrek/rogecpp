#pragma once
#include "ISpaceObject.h"
#include "INameble.h"

class Unit  : public ISpaceObject , public INameble
{
	struct Impl;

	unique_ptr<Impl> impl;

public:
	Unit();
	~Unit();
	
	virtual operator wchar_t() override;
	virtual wstring getName(Type t = Type::name) override;
	virtual void setName(wstring&& nm, Type t = Type::name) override;
	virtual wchar_t getChar() override;



};

