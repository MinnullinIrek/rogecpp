#pragma once
#include <memory>

class IItem;

class Bag final
{
private:
	struct Items;
	struct Impl;
	std::unique_ptr<Impl> impl;
public:
	Bag();
	~Bag();
	auto getSize();

	auto push_back(std::shared_ptr<IItem> item) -> void;
};

