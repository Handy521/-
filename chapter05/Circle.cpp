#include"Circle.h"
Circle::Circle(double radius)
{
	cout<<"Circle"<<endl;
	m_dRadius = radius;
}
Circle::~Circle()
{
	cout<<"~Circle"<<endl;
}
double Circle::calcArea()
{
	cout<<"Circle::caclArea()"<<endl; 
	return 3.14 * m_dRadius * m_dRadius;
}
