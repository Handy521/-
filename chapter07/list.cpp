#include<list>
#include<iostream> 
using namespace std;
#include"Coordinate.h" 
/*****************************************/
/* ����list
	Ҫ��
		1��ģ�����int,����ʹ��empty,push_back,pop_back,��ʹ�õ�����iterator����list����������Ԫ��
		2������ʹ�ò��빦��insert()*/ 
/*****************************************/

int main()
{
	list<int> list1;
	cout<<list1.empty()<<endl;
	list1.push_back(3);
	list1.push_back(5);
	list<int>::iterator iter = list1.begin();
	//list1.insert(iter,4);//�ڿ�ͷ����4 
	
	list<int> list2(3,8);//3��8 
	iter++;
	list1.insert(iter,list2.begin(),list2.end());//�ڵڶ���λ�ò���list2 
	
	//list<int>::iterator iter = list1.end();
	//list1.insert(iter,4,1);//��ĩβ����4 ��1 
	
	iter = list1.begin();
	for(;iter != list1.end();iter++)
		cout<<*iter<<endl;
	
}
