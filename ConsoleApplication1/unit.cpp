#include "stdafx.h"
#include "Unit.h"
#include "Mover.h"
#include "Characs.h"

struct Unit::Impl
{
	Name name;
	unique_ptr<Mover> mover;
	unique_ptr<Characs> chars;
};

wstring Unit::getName(Type t)
{
	return impl->name.name_descr[t];
}

void Unit::setName(wstring&& nm, Type t)
{
	impl->name.name_descr[t] = nm;
}

wchar_t Unit::getChar()
{
	return impl->name.ch;
}

void Unit::setMover(Mover* mover)
{
	impl->mover.reset(mover);
}

auto Unit::moveTo(size_t row, size_t col) -> void
{
	if (impl->mover)
		impl->mover->moveTo(Coords{ row, col });
}

shared_ptr<Cell> Unit::currentCell()
{
	return impl->mover->getCurrentCell();
}

Coords Unit::getCoord()
{
	return impl->mover->getCoord();
}

Value & Unit::getParam(const wstring& param)
{
	return impl->chars->getChar(param);
}

void Unit::initParams()
{
	impl->chars.reset(new Characs());
}

Unit::Unit(wchar_t ch) :impl(make_unique<Impl>())
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
