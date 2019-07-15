#pragma once
#include"Flyable.h"
class Men:public Flyable
{
public:
	void talk();
	virtual void takeoff();
	virtual void land();
 } ;
