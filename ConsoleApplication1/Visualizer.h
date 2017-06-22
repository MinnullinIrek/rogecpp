#pragma once

#include "Map.h"
#include "unit.h"
using namespace std;

class Visualizer
{
	weak_ptr<Map>	map;
	weak_ptr<Unit>	hero;
public:
	Visualizer();
	~Visualizer();

	auto show() -> void;

private:
	auto showMap(int row_start, int col_start) -> void;
};

