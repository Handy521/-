#include"Circle.h"
#include <iostream>
using namespace std;

Circle::Circle(int x,int y,int r) 
{
	cout << "Circle(int x,int y,int z)"<<endl;
	m_pCenter = new Coordinate(x,y);//ʵ����Բ�� ���ڶ��п���һ����ַ 
	m_iR = r;
}

Circle::~Circle()
{
	cout <<"~Circle()" << endl;
	delete m_pCenter;
	m_pCenter = NULL;
}
