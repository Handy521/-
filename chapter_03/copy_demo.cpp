#include "Circle2.h"
#include <iostream>
#include <iostream>
using namespace std;

/********************************************************/
/*
深拷贝/浅拷贝
	要求 ：
		1.定义Circle类。成员函数：构造函数，析构函数，printinfo数据成员：m_iR
		2.定义Coordinate类，成员函数：构造函数，析构函数，数据成员：m_iX,m_iY.
*/
/********************************************************/

int main(void)
{
	Circle c1(2,5,4);
	c1.printinfo();
	Circle c2(c1);
	c2.printinfo();
	system("pause");
	return 0;
 } 
