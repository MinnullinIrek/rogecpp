#pragma once

#include "utils.h"
#include <functional>

class Value
{
	struct Impl;
	unique_ptr<Impl> impl;
public:
	Value();
	Value(double v);
	Value(Value & val);

	~Value();

	operator double() ;
	operator int() ;
	Value& operator = (const Value &val);
	void setValue(double val);
	void setWatcher(function<void(double)>& watcher);

	friend Value operator *(const Value & left, const Value &right);
	friend Value operator /(const Value & left, const Value &right);
	friend Value operator +(const Value & left, const Value &right);
	friend Value operator -(const Value & left, const Value &right);
	friend bool operator==(const Value& left, const Value& right);
	friend Value& operator+=(Value& left, const Value& right);
	friend Value& operator-=(Value& left, const Value& right);
};

