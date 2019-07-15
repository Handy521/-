#include <iostream>
using namespace std;
#include <stdlib.h>
/******************************************/
/*函数模板
	关键字：template typename class
	
	要求：编写三个函数模板 
		1 求给定的两个参数和
		2 求给定参数的两倍
		3 求给定参数的n倍 
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

