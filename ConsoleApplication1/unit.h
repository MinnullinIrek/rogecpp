#pragma once
#include "ISpaceObject.h"
#include "INameble.h"
#include "Mover.h"

class Unit  : public ISpaceObject , public INameble
{
	struct Impl;

	unique_ptr<Impl> impl;


public:
	Unit(wchar_t ch);
	~Unit();
	
	virtual operator wchar_t() override;
	virtual wstring getName(Type t = Type::name) override;
	virtual void setName(wstring&& nm, Type t = Type::name) override;
	virtual wchar_t getChar() override;
	virtual void setMover(unique_ptr<Mover> mover);


};

