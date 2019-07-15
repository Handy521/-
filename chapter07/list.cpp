#include<list>
#include<iostream> 
using namespace std;
#include"Coordinate.h" 
/*****************************************/
/* 链表list
	要求：
		1、模板参数int,尝试使用empty,push_back,pop_back,并使用迭代器iterator遍历list对象中所有元素
		2、尝试使用插入功能insert()*/ 
/*****************************************/

int main()
{
	list<int> list1;
	cout<<list1.empty()<<endl;
	list1.push_back(3);
	list1.push_back(5);
	list<int>::iterator iter = list1.begin();
	//list1.insert(iter,4);//在开头插入4 
	
	list<int> list2(3,8);//3个8 
	iter++;
	list1.insert(iter,list2.begin(),list2.end());//在第二个位置插入list2 
	
	//list<int>::iterator iter = list1.end();
	//list1.insert(iter,4,1);//在末尾插入4 个1 
	
	iter = list1.begin();
	for(;iter != list1.end();iter++)
		cout<<*iter<<endl;
	
}
