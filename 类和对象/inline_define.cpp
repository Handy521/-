#include <iostream>
#include <stdlib.h>
using namespace std;
#define MAX(x,y) (x)>(y)?(x):(y)//����ַ��滻 

inline int max (int x, int y)
{
	return x>y?x:y;
 };
class XXX
{
	public:
		int max()
		{
			return x>y?x:y;
		}
 } ;
class Car
{
private:
	int wheelCount;
public:
	int getWheelCount();
};
int Car::getWheelCount()//���ⶨ�� 
{
	return wheelCount;
 } ;
 
int main()
{
	int x = 10;
	int y = 20,a;
	a = MAX(x,y);
	cout << a << endl;
 } 
