#pragma once 
#include <iostream>
#include<string>
using namespace std;

class MyException
{
	public:
		MyException(int code,string msg);//�������źʹ�����Ϣ 
		virtual int getErrorInfo(string &msg);//����һ�������õ�������Ϣ���൱��һ��ָ�� ����ֵ�����õ�ַ 
	protected:
		int m_iCode;
		string m_strMsg; 
};
