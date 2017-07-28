#pragma once
#include "utils.h"


class Item;

class Bag final
{
private:
	struct Items;
	struct Impl;
	unique_ptr<Impl> impl;
public:
	Bag();
	~Bag();
	auto getSize();

	auto push_back(shared_ptr<Item> item) -> void;

	auto watchItems() -> void;
	auto nextItem() -> shared_ptr<Item>;

};

