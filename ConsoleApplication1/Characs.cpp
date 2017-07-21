#include "stdafx.h"
#include <unordered_map>

#include "Characs.h"
#include "Value.h"

struct Characs::Impl
{
	unordered_map<wstring, Value> values;
};

void Characs::initCharacs()
{
	impl->values[L"hp"] = 0;
	impl->values[L"attack"] = 0;
}

Characs::Characs() :impl(make_unique<Impl>())
{
	initCharacs();
}


Characs::~Characs()
{
}

Value & Characs::getChar(const wstring& charName)
{
	return impl->values.at(charName);
}
