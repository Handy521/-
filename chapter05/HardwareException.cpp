#include"HardwareException.h"

HardwareException::HardwareException(int code, string msg):MyException(code,msg)
{
	cout<<"HardwareException"<<endl;
}

int HardwareException::getErrorInfo(string &msg)
{
	cout<<"HardwareException::getErrorInfo"<<endl;
	msg = m_strMsg;
	return m_iCode;
}
