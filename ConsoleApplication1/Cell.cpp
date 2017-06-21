#include "stdafx.h"
#include "Cell.h"
#include "ISpaceObject.h"


struct Cell::Impl
{
	std::unique_ptr<ISpaceObject> spceObj;
};

Cell::Cell():impl(std::make_unique<Impl>())
{
}


Cell::~Cell()
{
}

auto Cell::setSpaceObject(std::unique_ptr<ISpaceObject>&& spaceObject) -> void
{
	impl->spceObj.reset(spaceObject.release());
}

auto Cell::getSpaceObject() -> ISpaceObject *
{
	return impl->spceObj.release();
}

