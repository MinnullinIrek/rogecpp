#pragma once
#include <memory>

class Bag final
{
private:
	struct Items;
	struct Impl;
	std::unique_ptr<Impl> impl;
public:
	Bag();
	~Bag();
};

