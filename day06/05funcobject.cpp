#include <iostream>
using namespace std;

class Square
{
private:
	int m_d;
public:
	Square(int d = 0):m_d(d){}
	int operator()(void)
	{
		return m_d*m_d;
	}
};

int main()
{
	Square s(100);
	cout << s() << endl;
	
	return 0;	
}
