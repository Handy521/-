#include "Circle2.h"
#include <iostream>
using namespace std;
Circle::Circle(int x, int y,int r)
{
	m_iR = r;
	cout<< "Circle()"<<endl;
	m_pCenter = new Coordinated(x,y);
}
Circle::Circle(const Circle &c)
{
	cout<< "Circle(const Circle &c)"<<endl;
	m_iR = c.m_iR;
	m_pCenter = new Coordinated(c.m_pCenter->m_iX,c.m_pCenter->m_iY);
}
Circle::~Circle()
{
	cout<<"~Circle()"<<endl;
	
}
void Circle::printinfo()
{
	cout<< m_pCenter->m_iX<<","<<m_pCenter->m_iY<<","<<m_iR<<endl;
}
