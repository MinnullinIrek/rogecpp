#pragma once

class Cell;

class Map
{
private:
	struct Cells;
	struct Impl;

	unique_ptr<Impl> impl;

public:
	Map(size_t q, size_t r);
	~Map();
	auto getCell(size_t row, size_t col)->shared_ptr<Cell>;

	auto getCell(pair<size_t, size_t> && coord)->shared_ptr<Cell>;

	auto getCell(const pair<size_t, size_t> &coord) const ->shared_ptr<Cell> ;

};

