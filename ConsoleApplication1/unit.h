#pragma once
#include "utils.h"
#include "ISpaceObject.h"
#include "INameble.h"
#include "IMover.h"
#include <functional>

class Mover;
class Cell;
class Value;
class Bag;
class Item;
//class UnitCreator;

class Unit : public ISpaceObject, public INameble, public IMover
{
protected:
	friend class UnitCreator;
	struct Impl;

	unique_ptr<Impl> impl;

	Unit();
public:

	Unit(wchar_t ch);
	~Unit();

	virtual operator wchar_t() override;
	virtual wstring getName(Type t = Type::name) override;
	virtual void setName(wstring&& nm, Type t = Type::name) override;
	virtual wchar_t getChar() override;
	virtual void setMover(Mover* mover);
	virtual auto moveTo(crd row, crd col) -> void override;
	virtual auto directTo(crd row, crd col) -> void override;
	shared_ptr<Cell> currentCell();
	Coords getCoord();
	Value &getParam(const wstring & param);
	void initParams();
	
	function<void(shared_ptr<Unit>, shared_ptr<Unit>)> cooperator;
	void destroy();
	
	auto getBag() ->shared_ptr<Bag>;

	void pickUp(shared_ptr<Bag> bag, int itemNum);

	void wearItem(shared_ptr<Item> item, wstring type);
};

