#include"Flyable.h"
#include"Plane.h"
#include"Men.h"

/************************************/
//将Flyable类定义为接口类，父类为抽象类 
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
