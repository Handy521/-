#include<iostream>
#include <stdlib.h>
#include <string>
#include"Student.h"
using namespace std;

int main()
{ 
	Student stu;
	Student stu1(stu);
	Student stu2 = stu1;
	stu.setName("tim");
	stu.setAge(10);
	cout <<stu.getName()<<" "<<stu.getAge()<<endl; 
	stu.study();
	system("pause");
	return 0;
	
}
