#pragma once
#include"Human.h"
class Farmer: virtual public Human
{
public:
	Farmer(string name,int age);
	~Farmer();
	int getAge();
private:
	int m_iAge;
};
