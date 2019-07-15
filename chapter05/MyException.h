#pragma once 
#include <iostream>
#include<string>
using namespace std;

class MyException
{
	public:
		MyException(int code,string msg);//传入错误号和错误信息 
		virtual int getErrorInfo(string &msg);//传入一个引用拿到错误信息，相当于一个指针 ，将值赋给该地址 
	protected:
		int m_iCode;
		string m_strMsg; 
};
