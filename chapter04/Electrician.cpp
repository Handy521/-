#include "Electrician.h"
#include<iostream>
using namespace std;
Electrician::Electrician(string name,int age,int salary):Worker(name,age)
{
	//m_strName = name;
	m_iSalary = salary;
	cout<<"Electrician"<<endl;
}

Electrician::~Electrician()
{
	cout<<"~Electrician"<<endl;
}
void Electrician::printInfo() const
{
	//cout <<m_strName<<" ,"<<m_iSalary<<endl;//不能访问父类中private对象 
	cout <<getAge()<<" ,"<<m_iSalary<<endl;
	cout<<"Electrician::printInfo()" <<endl;
}
