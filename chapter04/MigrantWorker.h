#pragma once
#include"Farmer.h"
#include"Employee.h"
class MigrantWorker:public Farmer,public Employee
{
public:
	MigrantWorker(string name,int age,string code,int salary);
	~MigrantWorker();
	int getSalary();
protected:
	int m_iSalary;
};
