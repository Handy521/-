#include"Array.h"
#include"Coordinate.h"
/*********************************/
/*��ģ��
	Ҫ��
	1������������ģ��Array,��һ��ģ�����
	2��������ģ��Array,������ģ�����
	3���Զ������ʹ���Array      */
	
/*********************************/
int main()
{
	/*Array<double,10> arr1;//���������ڴ� 
	Array<int,5> *arr2 = new Array<int,5>();//ջ�������ڴ棬��Ҫ�Լ��ͷ� 
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
	arr3.display();//<<��������أ�����operator<<(cout,coor1)  
	
	return 0;
}
