#pragma once
#include"MyException.h"
class NetworkException:public MyException
{
	public:
		NetworkException(int code,string msg);
		virtual int getErrorInfo(string &msg);
};
