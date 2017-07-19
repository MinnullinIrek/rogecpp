#pragma once
#include "utils.h"


class IItem;

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

	auto push_back(shared_ptr<IItem> item) -> void;
};

