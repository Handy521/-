#include"Worker.h"
#include"Electrician.h"

#include<stdlib.h>

/********************************************/
/*多重继承
	Person类 
		数据成员：m_iAge;
		成员函数：构造函数，析构函数，getAge 
/*同名隐藏
	Worker类
		数据成员：m_strName
		成员函数：构造函数，析构函数，getName,printinfo 
	
	Electricain类   
		数据成员：m_iSalary
		成员函数：构造函数，析构函数，printinfo 
/*******************************************/
int main(void)
{
	//Electrician elec("JIm",200);
	Electrician *elec = new Electrician("JIn",20,2000);
	//elec->Worker::printInfo();
	elec->getName();//protected继承时不能访问 
	elec->printInfo();
	delete elec;
	elec = NULL;
	system("pause");
	return 0;
 } 
