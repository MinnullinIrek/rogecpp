#include "stdafx.h"
#include "Cell.h"
#include "ISpaceObject.h"


struct Cell::Impl
{
	shared_ptr<ISpaceObject> spceObj;
};

Cell::Cell():impl(std::make_unique<Impl>())
{
}


Cell::~Cell()
{
}

auto Cell::setSpaceObject(shared_ptr<ISpaceObject> spaceObject) -> void 
{
	impl->spceObj = spaceObject;
}

auto Cell::getSpaceObject() -> shared_ptr<ISpaceObject>
{
	return impl->spceObj;
}

