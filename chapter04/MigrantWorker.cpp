#include"MigrantWorker.h"

MigrantWorker::MigrantWorker(string name,int age,string code,int salary):Farmer(name,age),Employee(name,code),Human(name)
{
	m_iSalary = salary;
	cout<<"MigrantWorker()"<<endl;
}
MigrantWorker::~MigrantWorker()
{
	cout<<"~MigrantWorker()"<<endl;
 } 
int MigrantWorker::getSalary()
{
	return m_iSalary;
}
