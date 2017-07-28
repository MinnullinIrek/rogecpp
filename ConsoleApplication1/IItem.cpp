#include "stdafx.h"
#include "IItem.h"
#include "INameble.h"

struct Item::Impl
{
	Impl(ItemType tp):type(tp)
	{}

	ItemType type;
	Name nm;
};

Item::Item(ItemType type):impl(make_unique<Impl>(type))
{
}

Item::~Item()
{
}

auto Item::getType() -> ItemType
{
	return impl->type;
}

auto Item::getName(INameble::Type type) -> wstring
{
	return impl->nm.name_descr[type];
}

auto Item::setName(INameble::Type type, wstring value) -> void
{
	impl->nm.name_descr[type] = value;
}
