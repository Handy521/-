#include"NetworkException.h"
NetworkException::NetworkException(int code, string msg):MyException(code,msg)
{
	cout<<"NetworkException"<<endl;
}

int NetworkException::getErrorInfo(string &msg)
{
	cout<<"NetworkException::getErrorInfo"<<endl;
	msg = m_strMsg;
	return m_iCode;
}
