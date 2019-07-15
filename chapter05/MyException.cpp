#include"MyException.h"

MyException::MyException(int code ,string msg)
{
	cout<<"MyException"<<endl;
	m_iCode = code;
	m_strMsg = msg;
 } 

int MyException::getErrorInfo(string &msg)
{
	cout<<"MyException::getErrorInfo"<<endl;
	msg = m_strMsg;
	
	return m_iCode;
}
