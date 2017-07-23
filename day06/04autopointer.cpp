#include <iostream>
using namespace std;

class Int
{
private:
	int m_data;
public:
	Int(int n=0):m_data(n){}
	void print()
	{
		cout << m_data << endl;
	}
};

class AutoPoint
{
private:
	Int *m_p;
public:
	AutoPoint(const Int& i):m_p(new Int(i)){}
	AutoPoint(const AutoPoint& that)
	{
		m_p = new Int(*that.m_p);
	}
	AutoPoint& operator=(const AutoPoint& that)
	{
		if(&that != this)
		{
			Int* p = new Int(*that.m_p);
			delete [] m_p;
			m_p = p;
		}
		return *this;
	}
	~AutoPoint(void)
	{
		if(NULL != m_p)
		{
			delete[] m_p;
		}
		m_p = NULL;
	}
	Int& operator*()
	{
		return *m_p;
	}
	Int*& operator->()
	{
		return m_p;
	}
};

int main()
{
	//重载了＊ -> 操作符的类型对象，可以当作指针一样使用
	AutoPoint ap(*new Int(110));
	(*ap).print();
	ap->print();
	return 0;	
}
