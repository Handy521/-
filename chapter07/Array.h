#pragma once
#include<iostream>
using namespace std;

template<typename T,int size>
class Array
{
public:
	Array();
	void display();
	bool push(T a);
private:
	T *m_pArr;
	int m_iSize;
	int m_iLength;
};
template<typename T,int size>
Array<T,size>::Array()
{
	m_iSize = size;
	m_iLength = 0;
	m_pArr = new T[m_iSize];
}
template<typename T,int size>
void Array<T,size>::display()
{
	for(int i = 0;i < m_iLength;i++) 
		cout<<m_pArr[i]<<endl; //<<运算符重载,输出Coordinate对象 
}
template<typename T,int size>
bool Array<T,size>::push(T a)
{
	m_pArr[m_iLength] = a;
	m_iLength++;
}
