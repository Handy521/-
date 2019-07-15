#include "Employee.h"
#include <iostream>
using namespace std;

Employee::Employee(int year,int month,int day):m_tBirthday(year,month,day)
{
}
void Employee::testTime()
{
	m_tBirthday.printTime();
	cout<< m_tBirthday.m_iYear<<"_"<<m_tBirthday.m_iMonth<<"_"<<m_tBirthday.m_iDay<<endl;
}
