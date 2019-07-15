#pragma once
#include <string>
#include"Person.h"
using namespace std;
class Worker:protected Person//继承到子类的protected 
//class Worker:public Person
{
public:
	Worker(string name,int age);
	~Worker();
	string getName() const;
	void printInfo(); 
protected:
private:
	string m_strName;
};
