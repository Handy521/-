#include<iostream>
#include<vector>
using namespace std;
#include"Coordinate.h" 
/*****************************************/
/*向量vector
	要求：
	   1、模板参数int,尝试使用empty,push_back,pop_back,size,front,back及下标访问元素
	   2、模板参数Coordinate
	   3、使用迭代器iterator遍历vector对象中所有元素*/ 
/*****************************************/

int main()
{
	
	/*vector<int> vec;
	cout<<vec.empty()<<endl;	
	vec.push_back(10);
	vec.push_back(12);
	vec.push_back(15);
	cout<<vec.front()<<","<<vec.back()<<endl;
	cout<<vec.size()<<endl;  
	vec.pop_back();//后入先出 
	for (int i = 0; i<vec.size();i++)
		cout<<vec[i]<<endl;*/
		
	vector<Coordinate> vec1;	
	Coordinate coor1(3,5);
	Coordinate coor2(13,5);
	Coordinate coor3(3,15);
	vec1.push_back(coor1);
	vec1.push_back(coor2);
	vec1.push_back(coor3);
	vector<Coordinate>::iterator iter = vec1.begin();//iterator是一个嵌套类，实例化一个对象 
	for (;iter != vec1.end();iter++)//end为当前向量末尾的下一个元素 
		cout<<*iter<<endl;

	return 0;
 } 
