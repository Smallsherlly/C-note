#include <iostream>
using namespace std;

class IntPoint
{
private:
	int *m_p;
public:
	IntPoint(int num):m_p(new int(num)){}
	IntPoint(const  IntPoint& that):m_p(new int(*that.m_p)){}
	IntPoint& operator=(const IntPoint& that)
	{
		if(&that !=this)
		{
			*m_p = *that.m_p;
		}
	}	
	~IntPoint(void)
	{
		if(m_p != NULL)
		{
			delete m_p;
		}
		m_p = NULL;
	}
	int operator*(void)
	{
		return *m_p;
	}
	int* operator&(void)
	{
		return m_p;
	}
};

int main()
{
	IntPoint ip1(110);
	cout << *ip1 << endl;
	cout << &ip1 << endl;

	return 0;	
}
