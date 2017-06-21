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
		if (i <= this->size())
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

};

struct Bag::Impl
{
	

};

Bag::Bag()
{
}


Bag::~Bag()
{
}
