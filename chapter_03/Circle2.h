#include "Coordinated.h"
class Circle
{
	public:
		Circle(int x, int y,int r);
		Circle(const Circle &c);//��� 
		~Circle();
		void printinfo();
	private:
		Coordinated *m_pCenter;
		int m_iR;
};
