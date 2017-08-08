#include "stdafx.h"
#include <unordered_map>

#include "Bag.h"
#include "IItem.h"


struct Bag::Impl
{
	unordered_map<ItemType, shared_ptr<Item>> items;
	unordered_map<ItemType, shared_ptr<Item>>::iterator it;
};

Bag::Bag():impl(make_unique<Impl>())
{
}


Bag::~Bag()
{
}

auto Bag::getSize()
{
	return 0;
}

auto Bag::push_back(shared_ptr<Item> item) -> void
{
	impl->items.insert(make_pair<ItemType, shared_ptr<Item> >(item->getType(), move(item)));
}

auto Bag::watchItems() -> void
{
	impl->it = impl->items.begin();
}

auto Bag::nextItem() -> shared_ptr<Item>
{
	if (impl->it != impl->items.end())
		return (impl->it++)->second;
	else
		return shared_ptr<Item>(nullptr);
}

auto Bag::begin() -> unordered_map<ItemType, shared_ptr<Item>>::iterator
{
	return impl->items.begin();
}

auto Bag::end() -> unordered_map<ItemType, shared_ptr<Item>>::iterator
{
	return impl->items.end();
}



