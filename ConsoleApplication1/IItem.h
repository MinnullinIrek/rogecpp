#pragma once
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

class Item 
{

	struct Impl;

	unique_ptr<Impl> impl;

public:
	Item(ItemType type);
	~Item();
	auto getType()->ItemType;

	auto getName(INameble::Type type)->wstring;
	auto setName(INameble::Type type, wstring value)->void;



};

