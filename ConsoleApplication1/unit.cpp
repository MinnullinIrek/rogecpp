#include "stdafx.h"
#include "Unit.h"
#include "Mover.h"

struct Unit::Impl
{
	Name name;
	unique_ptr<Mover> mover;
};

wstring Unit::getName(Type t)
{
	return impl->name.name_descr[t];
}

void Unit::setName(wstring&& nm, Type t )
{
	impl->name.name_descr[t] = nm;
}

wchar_t Unit::getChar()
{
	return impl->name.ch;
}

void Unit::setMover(unique_ptr<Mover> mover)
{
	impl->mover.reset(mover.get());
}

Unit::Unit(wchar_t ch):impl(make_unique<Impl>())
{
	impl->name.ch = ch;
}


Unit::~Unit()
{
}

Unit::operator wchar_t()
{
	return getChar();
}
