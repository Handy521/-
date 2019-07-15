#pragma once
#include "Human.h"

class Employee: virtual public  Human
{
public:
	Employee(string name,string code);
	~Employee();
	string getCode();
protected:
	string m_strCode;
};
