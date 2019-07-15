#include"Circle.h"
#include <iostream>
#include <stdlib.h>
using namespace std;

int main()
{
	Circle *p = new Circle(3,5,7);
	delete p;
	p = NULL;
	system("pause");
	return 0;
	
}
