#include"Flyable.h"
#include"Plane.h"
#include"Men.h"

/************************************/
//��Flyable�ඨ��Ϊ�ӿ��࣬����Ϊ������ 
/***********************************/
void dosomething(Flyable *obj);

int main()
{
	Flyable *obj1 = new Plane();
	Flyable *obj2 = new Men();
	
	dosomething(obj1);
	dosomething(obj2);
	delete obj1;
	delete obj2;
	obj1 = NULL;
	obj2 = NULL;
	return 0;
}

void dosomething(Flyable *obj)
{
	obj->land();
	obj->takeoff();
}
