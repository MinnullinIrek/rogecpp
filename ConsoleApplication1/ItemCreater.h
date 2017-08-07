#pragma once
#include "utils.h"

class Item;

class ItemCreater
{
public:
	ItemCreater();
	~ItemCreater();
	static shared_ptr<Item> createItem(wstring name);
};

