#pragma once
#include "utils.h"

class Cell;

class Map
{
private:
	struct Cells;
	struct Impl;

	unique_ptr<Impl> impl;

public:
	Map(crd q, crd r);
	~Map();
	auto getCell(crd row, crd col, bool isCreatable)->shared_ptr<Cell>;

	auto getCell(Coords && coord, bool isCreatable)->shared_ptr<Cell>;

	auto getCell(const Coords &coord, bool isCreatable) const->shared_ptr<Cell>;

	auto getSize() const->Coords;

};

