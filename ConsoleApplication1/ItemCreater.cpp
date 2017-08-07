#include "stdafx.h"
#include "ItemCreater.h"
#include "IItem.h"


ItemCreater::ItemCreater()
{
}


ItemCreater::~ItemCreater()
{
}

shared_ptr<Item> ItemCreater::createItem(wstring name)
{
	shared_ptr<Item> item = make_shared<Item>(ItemType::armour);

	item->setName(INameble::Type::name, name);

	return item;
}
