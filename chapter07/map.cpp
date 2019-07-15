#include<map>
#include<string> 
#include<iostream>
#include"Coordinate.h"
using namespace std;
/***********************************************/
/*映射map
	要求：
		1、模板参数int，string，使用下标访问键值
		2、使用迭代器iterator遍历map对象中所有元素
		3、模板参数string、Coordinate，查看效果*/
/***********************************************/
int main()
{
/*	map<int,string> map1;
	pair<int,string> p1(3,"zhangsan");
	pair<int,string> p2(4,"wangwu");
	map1.insert(p1);
	map1.insert(p2);
	
//	cout<<map1[3]<<endl;
//	cout<<map1[4]<<endl;
	
	map<int,string>::iterator iter = map1.begin();
	for(;iter != map1.end();iter++)
	{
		cout<<(*iter).first<<endl;
		cout<<(*iter).second<<endl;
		cout<<endl;
	 } */
	map<string,Coordinate> map1;
	Coordinate coor1(3,5);
	Coordinate coor2(5,8);
	pair<string,Coordinate> p1("beijing",coor1);
	pair<string,Coordinate> p2("guangzhou",coor2);
	map1.insert(p1);
	map1.insert(p2);
	
//	cout<<map1["beiging"]<<endl;
//	cout<<map1["guangzhou"]<<endl;
	
	map<string,Coordinate>::iterator iter = map1.begin();
	for(;iter != map1.end();iter++)
	{
		cout<<(*iter).first<<endl;
		cout<<(*iter).second<<endl;
		cout<<endl;
	 }  
	return 0;
 } 
