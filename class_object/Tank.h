#include<string>
using namespace std;
class Tank
{
public:
	Tank(string code);
	~Tank();
	void attack();
	static int getCount();
private:
	string m_strCode;
	static int g_iCount;
};
