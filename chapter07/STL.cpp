#include<iostream>
#include<vector>
using namespace std;
#include"Coordinate.h" 
/*****************************************/
/*����vector
	Ҫ��
	   1��ģ�����int,����ʹ��empty,push_back,pop_back,size,front,back���±����Ԫ��
	   2��ģ�����Coordinate
	   3��ʹ�õ�����iterator����vector����������Ԫ��*/ 
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
	vec.pop_back();//�����ȳ� 
	for (int i = 0; i<vec.size();i++)
		cout<<vec[i]<<endl;*/
		
	vector<Coordinate> vec1;	
	Coordinate coor1(3,5);
	Coordinate coor2(13,5);
	Coordinate coor3(3,15);
	vec1.push_back(coor1);
	vec1.push_back(coor2);
	vec1.push_back(coor3);
	vector<Coordinate>::iterator iter = vec1.begin();//iterator��һ��Ƕ���࣬ʵ����һ������ 
	for (;iter != vec1.end();iter++)//endΪ��ǰ����ĩβ����һ��Ԫ�� 
		cout<<*iter<<endl;

	return 0;
 } 
