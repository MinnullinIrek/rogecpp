#pragma once
#include <unordered_map>

#include "utils.h"


class Item;
enum class ItemType;

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

	auto begin() ->  unordered_map<ItemType, shared_ptr<Item>>::iterator;
	auto end() -> unordered_map<ItemType, shared_ptr<Item>>::iterator;


};

