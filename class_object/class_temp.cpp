#include <iostream>
#include <stdlib.h>
using namespace std;

class Car
	{
		public:
			int getWheelCount() //属性的封装 
			{
				return wheelCount;
			}
		private:
			int wheelCount;//只读属性 
	};
int main()
	{
		//system("pause");
		Car car;//栈中定义一个类 
		car.getWheelCount();
		Car *p = new Car();//堆中实例化一个类需要delete 
		p->getWheelCount(); 
		delete p;
		p = NULL;
		return 0; 
	}
