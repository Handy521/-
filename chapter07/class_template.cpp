#include"Array.h"
#include"Coordinate.h"
/*********************************/
/*类模板
	要求：
	1、定义数组类模板Array,带一个模板参数
	2、改造类模板Array,带两个模板参数
	3、自定义类型存入Array      */
	
/*********************************/
int main()
{
	/*Array<double,10> arr1;//堆中申请内存 
	Array<int,5> *arr2 = new Array<int,5>();//栈中申请内存，需要自己释放 
	arr1.push(2);
	arr1.push(3.2);
	arr1.push(10.1);
	arr1.display();
	arr2->push(5678);
	arr2->display();
	delete []arr2;
	arr2 = NULL;*/ 
	Array<Coordinate,3> arr3;
	Coordinate coor1(3,5);
	Coordinate coor2(10,8);
	arr3.push(coor1);
	arr3.push(coor2);
	arr3.display();//<<运算符重载，调用operator<<(cout,coor1)  
	
	return 0;
}
