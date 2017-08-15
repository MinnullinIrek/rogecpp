#pragma once
#include <functional>

#include "utils.h"
#include "INameble.h"

enum class ItemType
{
	simple =0,
	armour,
	weapon,
	scroll,
	poution,
	staff,
	mech
};

class Value;
class Unit;




class Item 
{

	struct Impl;

	unique_ptr<Impl> impl;

	static long s_id;

public:
	Item(ItemType type = ItemType::simple);
	~Item();
	auto getType()->ItemType;

	auto getName(INameble::Type type)->wstring;
	auto setName(INameble::Type type, wstring value)->void;
	const long id;

	Value &getParam(const wstring & param);


	function<void(shared_ptr<Unit>, shared_ptr<Unit>)> getCooperator(wstring coopType);

	void setCooperator(wstring coopType, function<void(shared_ptr<Unit>, shared_ptr<Unit>)> func);

};

