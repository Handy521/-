#include <stdlib.h>
#include "Student.h"
using namespace std;

/***********************************************/
/* ����Ա�����������󡢳�����ָ�롢����������
	Ҫ��
		������Student����Ա���������캯����printinfo������
						���ݳ�Ա������m_strName
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
