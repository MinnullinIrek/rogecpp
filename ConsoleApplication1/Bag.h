#pragma once
#include <unordered_map>
#include <functional>

#include "utils.h"


class Item;
enum class ItemType;

enum class BagItemDo
{
	next = 0,
	select = 1,
	stop = 2,
	eraseStop = 3
};


class Bag final
{
private:
	struct Items;
	struct Impl;
	unique_ptr<Impl> impl;
public:
	Bag();
	~Bag();
	auto getSize()  -> int ;

	auto push_back(shared_ptr<Item> item) -> void;

	void forEach(function<BagItemDo(shared_ptr<Item> item)> func);

};

