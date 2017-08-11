#pragma once
#include <unordered_map>
#include <functional>

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
	auto getSize()  -> int ;

	auto push_back(shared_ptr<Item> item) -> void;

	void forEach(function<void(shared_ptr<Item> item)> func);

};

