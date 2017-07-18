#pragma once
#include <memory>
using namespace std;

class ISpaceObject;
class Cell
{
private:
	struct Impl;
	std::unique_ptr<Impl> impl;
public:
	Cell();
	virtual ~Cell();
	auto setSpaceObject(shared_ptr<ISpaceObject> spaceObject) -> void;
	auto getSpaceObject() -> shared_ptr<ISpaceObject>;
	operator wchar_t();
	auto getChar() -> wchar_t;
};

