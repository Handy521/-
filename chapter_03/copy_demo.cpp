#include "Circle2.h"
#include <iostream>
#include <iostream>
using namespace std;

/********************************************************/
/*
���/ǳ����
	Ҫ�� ��
		1.����Circle�ࡣ��Ա���������캯��������������printinfo���ݳ�Ա��m_iR
		2.����Coordinate�࣬��Ա���������캯�����������������ݳ�Ա��m_iX,m_iY.
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
