#include "stdafx.h"
#include <unordered_map>

#include "IItem.h"
#include "INameble.h"
#include "Value.h"


long Item::s_id = 0;

struct Item::Impl
{
	Impl(ItemType tp):type(tp), nm()
	{}

	ItemType type;
	Name nm;

	unordered_map<wstring, Value> values;
	
	unordered_map<wstring, function<void(shared_ptr<Unit>, shared_ptr<Unit>)> > activations;

};

Item::Item(ItemType type):impl(make_unique<Impl>(type)), id(s_id++)
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
	return impl->nm.name_descr[(unsigned int)type];
}

auto Item::setName(INameble::Type type, wstring value) -> void
{
	impl->nm.name_descr[type] = value;
}

Value & Item::getParam(const wstring & param)
{
	return impl->values[param];
}

function<void(shared_ptr<Unit>, shared_ptr<Unit>)> Item::getCooperator(wstring coopType)
{
	return impl->activations.at(coopType);
}

void Item::setCooperator(wstring coopType, function<void(shared_ptr<Unit>, shared_ptr<Unit>)> func)
{
	impl->activations[coopType] = func;
}

