#include "Worker.h"

class Electrician : public Worker
{
public:
	Electrician(string name,int age,int salary);
	~Electrician();
	void printInfo() const;
protected:
private:
	int m_iSalary;
};
