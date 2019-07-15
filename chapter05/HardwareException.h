#pragma once
#include"MyException.h"

class HardwareException:public MyException
{
	public:
		HardwareException(int code,string msg);
		virtual int getErrorInfo(string &msg);
 } ;
