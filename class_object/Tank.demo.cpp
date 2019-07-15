#include "Tank.h"
#include <iostream>
#include<stdlib.h>
using namespace std;

int main()
{
	/*Tank tank("123");
	tank.attack();
	Tank tank1("23");
	tank1.attack();
	Tank tank2("234");
	tank2.attack();
	Tank tank3("35");
	tank3.attack();*/
	Tank *p = new Tank("123");
	//p[0]  = "123"
	cout<<Tank::getCount()<<endl; 
	delete p;
	p = NULL;
	cout<<Tank::getCount()<<endl;
	system("pause");
	return 0;
}
