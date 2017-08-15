#include "stdafx.h"
#include <list>


#include "Value.h"

struct Value::Impl
{
	Impl(double v) : val(v) {}
	double val;
	list<function<void(double)>> watchers;

};

Value::Value() :impl(make_unique<Impl>(0))
{
}

Value::Value(double v) : impl(make_unique<Impl>(v))
{
}

Value::Value(Value & val) : impl(make_unique<Impl>(val))
{
}



Value::~Value()
{
}

Value::operator double() 
{
	return impl->val;
}

Value::operator int() 
{
	return static_cast<int>(impl->val);
}

Value & Value::operator=(const Value & val)
{
	if (this != &val)
		setValue(val.impl->val);
	return *this;
}

void Value::setValue(double val)
{
	impl->val = val;
	for (auto it : impl->watchers)
		it(val);
}

void Value::setWatcher(function<void(double)>& watcher)
{
	impl->watchers.push_back(watcher);
}

Value operator*(const Value & left, const Value & right)
{
	return move(Value(left.impl->val * right.impl->val));
}

Value operator/(const Value & left, const Value & right)
{
	return move(Value(left.impl->val / right.impl->val));
}

Value operator+(const Value & left, const Value & right)
{
	return move(Value(left.impl->val + right.impl->val));
}

Value  operator-(const Value & left, const Value & right)
{
	return Value(left.impl->val - right.impl->val);
}

bool operator==(const Value & left, const Value & right)
{
	return left.impl->val == right.impl->val;
}

Value & operator+=(Value & left, const Value & right)
{
	left.setValue(left.impl->val + right.impl->val);
	return left;
}

Value & operator-=(Value & left, const Value & right)
{
	left.setValue(left.impl->val - right.impl->val);
	return left;
}
