#include"Shape.h"
#include"Rectangle.h"
#include"Circle.h"
#include<stdlib.h>
/*****************/
/*��̬������ָ��ָ������������������������ͷ������ڴ�
       ��̳п��Ե�������ͬ������ ��ʵ�ֶ�̬ 
/****************/ 
int main()
{
	Shape *p1 = new Rectangle(2.0,3.0);
	Shape *p2 = new Circle(4.0);
	cout<<p2->calcArea()<<endl;
	cout<<p1->calcArea()<<endl;
	delete p1;//ִ��ʱ�����������ֽ�� 
	delete p2; 
	p1 = NULL;
	p2 = NULL;
	return 0;
}
