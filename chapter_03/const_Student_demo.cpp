#include <stdlib.h>
#include "Student.h"
using namespace std;

/***********************************************/
/* 常成员函数、常对象、常对象指针、常对象引用
	要求：
		定义类Student，成员函数：构造函数、printinfo常函数
						数据成员：姓名m_strName
/***********************************************/

int main(void)
 {
	Student stu1("Jim");
	stu1.printinfo();
	
	Student const stu2("merry");
	stu2.printinfo();
	 
	Student const *p = new Student("James");
	p->printinfo();
	
	Student const &stu3 = stu1;
	stu3.printinfo();
	 
	system("pause");
	return 0;
 } 
