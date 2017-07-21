#include "stdafx.h"
#include <vector>

#include "Bag.h"
#include "IItem.h"

struct Bag::Items : protected vector<shared_ptr<IItem>>
{
	Items()
	{

	}

	auto getItem(size_t i) -> shared_ptr<IItem>
	{
		if (i <= vector<shared_ptr<IItem>>::size())
			return shared_ptr<IItem>(nullptr);

		return this->at(i);
	}

	auto operator[](size_t i) -> shared_ptr<IItem>
	{
		return getItem(i);
	}

	auto push_back(shared_ptr<IItem>&& item) -> void
	{
		vector<shared_ptr<IItem>>::push_back(move(item));
	}

	auto size()
	{
		return vector<shared_ptr<IItem>>::size();
	}

};

struct Bag::Impl
{
	Items items;
};

Bag::Bag()
{
}


Bag::~Bag()
{
}

auto Bag::getSize()
{
	return impl->items.size();
}

auto Bag::push_back(shared_ptr<IItem> item) -> void
{
	impl->items.push_back(move(item));
}
