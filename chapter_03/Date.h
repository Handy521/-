#pragma once
class Employee;
class Date
{
	friend Employee;
	public:
		Date(int year,int month,int day);
	private:
		void printTime();
		int m_iYear;
		int m_iMonth;
		int m_iDay;
 } ;
