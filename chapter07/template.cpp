#include <iostream>
using namespace std;
#include <stdlib.h>
/******************************************/
/*����ģ��
	�ؼ��֣�template typename class
	
	Ҫ�󣺱�д��������ģ�� 
		1 �����������������
		2 ���������������
		3 �����������n�� 
/******************************************/
template<class T>
T add(T a,T b)
{
	return a + b;
}
template<typename T>
T multiply(T a)
{
	return a * 2;
}
template<class T,int n>
T multiple(T a)
{
	return a * n;
}
int main()
{
	cout<<add<double>(3.2,5)<<endl;
	cout<<multiply<double>(5.2)<<endl;
	cout<<multiple<double,10>(5)<<endl;
	return 0;
 } 

