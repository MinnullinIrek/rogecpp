#pragma once
#include "utils.h"

enum class ItemType;

class IItem
{
protected:

	struct Impl {};

	unique_ptr<Impl> impl;
public:
	IItem();

	
};

