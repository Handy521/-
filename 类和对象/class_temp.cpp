#include <iostream>
#include <stdlib.h>
using namespace std;

class Car
	{
		public:
			int getWheelCount() //���Եķ�װ 
			{
				return wheelCount;
			}
		private:
			int wheelCount;//ֻ������ 
	};
int main()
	{
		//system("pause");
		Car car;//ջ�ж���һ���� 
		car.getWheelCount();
		Car *p = new Car();//����ʵ����һ������Ҫdelete 
		p->getWheelCount(); 
		delete p;
		p = NULL;
		return 0; 
	}
