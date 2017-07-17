#pragma once


class Map
{
private:
	struct Impl;
	struct Cells;
	std::unique_ptr<Impl> impl;
public:
	Map(size_t rowCount = 0, size_t colCount = 0);
	~Map() = default;
	auto getCell(size_t row, size_t col)->shared_ptr<Cell>;


};

