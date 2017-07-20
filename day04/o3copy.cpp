#include <iostream>
using namespace std;

class IntPoint
{
	int* m_p;
public:
	IntPoint(int num)
	{
	//	m_p = new int(num);
		m_p = new int;
		*m_p = num;
	}
	IntPoint(const IntPoint& that)
	{
//		IntPoint i = that;
		m_p = new int(*that.m_p);
	}
};

int main()
{
	IntPoint i(3);
	IntPoint j(i);
	cout << j.getNum() << endl;
	return 0;
}
