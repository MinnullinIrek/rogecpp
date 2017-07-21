#pragma once
#include "utils.h"

class Value;

class Characs
{
	struct Impl;
	unique_ptr<Impl> impl;
	void initCharacs();
public:
	Characs();
	~Characs();

	Value& getChar(const wstring &charName);


};

