#include "stdafx.h"
#include "Cell.h"
#include "ISpaceObject.h"
#include "unit.h"
#include "Bag.h"

struct Cell::Impl
{
	shared_ptr<Unit> spceObj;
	shared_ptr<Bag> bag;
};

Cell::Cell() :impl(make_unique<Impl>())
{
}


Cell::~Cell()
{
}

auto Cell::setSpaceObject(shared_ptr<Unit> spaceObject) -> void
{
	impl->spceObj = spaceObject;
}

auto Cell::getSpaceObject() -> shared_ptr<Unit>
{
	return impl->spceObj;
}

Cell::operator wchar_t()
{
	return getChar();
}

auto Cell::getChar() -> wchar_t
{
	if (impl->spceObj.get() != nullptr)
		return impl->spceObj->getChar();
	else if ( impl->bag && impl->bag->getSize() > 0)
		return '$';
	
	return static_cast<wchar_t>(' ');
}

auto Cell::isEmpty() -> bool
{
	return impl->spceObj.get() == nullptr;
}

void Cell::resetSpaceObject()
{
	impl->spceObj.reset();
}

auto Cell::getBag() -> shared_ptr<Bag>
{
	if (!impl->bag)
		impl->bag = make_shared<Bag>();
	return impl->bag;
}

