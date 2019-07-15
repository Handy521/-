#pragma once

#include"Students.h"
#include<iostream>
using namespace std;

class Time
{
	//friend void printTime(Time &t);
	friend void Students::display(Time &t);
public:
	Time(int year,int month,int day)
	{
		m_iYear = year;
		m_iMonth = month;
		m_iDay = day;
	}
private:
	int m_iYear;
	int m_iMonth;
	int m_iDay;
};
