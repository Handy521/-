#include<iostream>
#include "Time.h"
#include"Students.h"
using namespace std;
void Students::display(Time &t)
{
	cout <<t.m_iYear<<"-"<<t.m_iMonth<<"-"<<t.m_iDay<<endl;
}
