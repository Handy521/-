#include<iostream>
#include"stdlib.h"
#include"Time.h"
#include"Students.h"
using namespace std;
/************************************/
/*��Ԫȫ�ֺ���
	��Ԫ��Ա����*/ 


/***********************************/

///void printTime(Time &t);

int main(void)
{
	Time t1(2015,10,20);
	Students stu;
	stu.display(t1);
	//printTime(t1);
	system("pause");
	return 0;
}

/*void printTime(Time &t)
{
	cout <<t.m_iYear<<"-"<<t.m_iMonth<<"-"<<t.m_iDay<<endl;
}*/
