#pragma once
#include<iostream>
using namespace std;

class Flyable
{
public:
	virtual void takeoff() = 0;
	virtual void land() = 0; 
};
