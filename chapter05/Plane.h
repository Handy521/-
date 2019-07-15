#pragma once
#include "Flyable.h"
class Plane:public Flyable
{
public:
	void carry();
	virtual void takeoff();
	virtual void land();
};
