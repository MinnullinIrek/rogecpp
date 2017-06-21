#pragma once
#include <memory>

class ISpaceObject;
class Cell
{
private:
	struct Impl;
	std::unique_ptr<Impl> impl;
public:
	Cell();
	virtual ~Cell();
	auto setSpaceObject(std::unique_ptr<ISpaceObject>&& spaceObject) -> void;
	auto getSpaceObject() -> ISpaceObject*;
};

