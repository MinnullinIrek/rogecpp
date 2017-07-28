#include "stdafx.h"


#include "Bag.h"
#include "IItem.h"


struct Bag::Impl
{

};

Bag::Bag()
{
}


Bag::~Bag()
{
}

auto Bag::getSize()
{
	return 0;
}

auto Bag::push_back(shared_ptr<IItem> item) -> void
{
	//impl->items.push_back(move(item));
}
