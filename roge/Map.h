#pragma once
#include <memory>

class Map
{
private:
	struct Impl;
	struct Cells;
	std::unique_ptr<Impl> impl;
public:
	Map();
	~Map();
};

