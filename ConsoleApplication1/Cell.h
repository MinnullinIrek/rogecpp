#pragma once
#include <memory>
using namespace std;

class Unit;
class Bag;

class Cell
{
private:
	struct Impl;
	unique_ptr<Impl> impl;
public:
	Cell();
	virtual ~Cell();
	auto setSpaceObject(shared_ptr<Unit> spaceObject) -> void;
	auto getSpaceObject()->shared_ptr<Unit>;
	operator wchar_t();
	auto getChar() -> wchar_t;
	auto isEmpty() -> bool;
	void resetSpaceObject();
	auto getBag()->shared_ptr<Bag>;
};

