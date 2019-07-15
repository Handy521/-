#include"Date.h"
#include<iostream>
using namespace std;

Date::Date(int year,int month,int day)
{
	m_iYear = year;
	m_iMonth = month;
	m_iDay = day;
}
void Date::printTime()
{
	cout<<m_iYear<<"year"<<m_iMonth<<"month"<<m_iDay<<"day"<<endl;
}
