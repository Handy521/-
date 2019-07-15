#include"Rectangle.h"
Rectangle::Rectangle(double width,double height)
{
	cout << "Rectangle"<<endl;
	m_dWidth = width;
	m_dHeight = height; 
 } 
Rectangle::~Rectangle()
{
	cout<<"~Rectangle"<<endl;
}
double Rectangle::calcArea()
{
	cout<<"Rectangle::calcArea()"<<endl;
	return m_dWidth * m_dHeight; 
}
