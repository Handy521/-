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
	//cout <<m_strName<<" ,"<<m_iSalary<<endl;//���ܷ��ʸ�����private���� 
	cout <<getAge()<<" ,"<<m_iSalary<<endl;
	cout<<"Electrician::printInfo()" <<endl;
}
