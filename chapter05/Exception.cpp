 #include"ErrorCode.h"
 #include"MyException.h"
 #include"HardwareException.h" 
 #include"NetworkException.h"
 #include<iostream>
 using namespace std;
 
 /********************************/
 /*�쳣����
       1��ƽ�нṹ fun1
	   2�����νṹ fun2*/
/********************************/
enum MathException
{
	ZeroException = 10,
	NegativeException = 20,
	NoSolutionException = 30
 } ;
 
void fun1(int flag)
{
	switch(flag)
	{
	case 0:
		throw ZeroException;
		break;
	case 1:
		throw NegativeException;
		break;
	case 2:
		throw NoSolutionException;
		break;
	}
}
void fun2(int flag)
{
	switch(flag)
	{
	case 0:
		throw MyException(ERR_UNK,string(ERR_UNK_MSG));
		break;
	case 1:
		throw HardwareException(ERR_TIME_OUT,string(ERR_TIME_OUT_MSG));
		break;
	case 2:
		throw NetworkException(ERR_CARD,string(ERR_CARD_MSG));
		break;
	}
}
int main()
{
	try 
	{
		//fun1(1);
		fun2(2);
	} 
	/*catch(MathException e)
	{
		cout<<"exception: "<<e<<endl;
	}*/
	catch(MyException &e)//���������ָ�����࣬ʵ�ֶ�̬ 
	{
		string msg;
		cout<<e.getErrorInfo(msg)<<endl;
		cout<<msg<<endl;
	}

	return 0;
}
