#include"Shape.h"
#include"Rectangle.h"
#include"Circle.h"
#include<stdlib.h>
/*****************/
/*多态：父类指针指向子类对象，虚析构函数可以释放子类内存
       虚继承可以调用子类同名函数 ，实现多态 
/****************/ 
int main()
{
	Shape *p1 = new Rectangle(2.0,3.0);
	Shape *p2 = new Circle(4.0);
	cout<<p2->calcArea()<<endl;
	cout<<p1->calcArea()<<endl;
	delete p1;//执行时报错，换个名字解决 
	delete p2; 
	p1 = NULL;
	p2 = NULL;
	return 0;
}
