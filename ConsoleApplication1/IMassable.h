#pragma once
#include "IProperty.h"

class IMassable abstract : public IProperty
{
public:
	virtual float getMass() = 0;
	virtual void setMass(float mass) = 0;
};

