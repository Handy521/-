#include<iostream>
#include "House.h"
#include "Furniture.h"//���� 
#include <string>
using namespace std;

int main()
{
	House *p = new House("1000","Bed1");//ʵ����һ���� 
//	p->getFur().setName("Bed");
	cout << p->getFur().getName()<< endl;
	delete p;
	p=NULL;
	system("pause");
	return 0  ;
 } 
