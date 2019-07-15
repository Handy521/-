#include "Student.h"
#include<iostream>
using namespace std;

Student::Student(string name)
{
	m_strName = name;
}

void Student::printinfo()
{
	cout<<"printinfo()"<<endl;
}
void Student::printinfo() const
{
	cout<<"printinfo()const"<<endl;
}
