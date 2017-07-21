#pragma once

class Unit;

class UnitCreator
{
public:
	UnitCreator();
	~UnitCreator();

	static shared_ptr<Unit> createUnit(wchar_t ch);
};

