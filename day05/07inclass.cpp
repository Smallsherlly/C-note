#include <iostream>
using namespace std;

class Int
{
private:
	int m_d;
public:
	Int(int d = 0):m_d(d){}
	Int(const Int& that)
	{
		m_d = that.m_d;
	}
	Int& operator=(const Int& that)
	{
		if(&that != this)
		{
			m_d = that.m_d;
		}
		return *this;
	}
	void show()
	{
		cout << m_d << endl;	
	}

	Int operator-(void)
	{
		return Int(-m_d);
//		Int temp(-m_d);
//		return temp;
	}
	bool operator!()
	{
		return m_d==0?true:false;
	}
	Int& operator++()
	{
		++m_d;
		return *this;
	}
	Int operator++(int)
	{
		Int t(m_d);
		++m_d;
		return t;
	}
	Int& operator--()
	{
		--m_d;
		return *this;
	}
	Int operator--(int)
	{
		Int t(m_d);
		--m_d;
		return t;
	}
};

int main()
{
	Int d1 = 100;
	Int d2;
	Int d3(20);
//	d2 = d1 + d3;
	d2 = d3;
	d2.show();
	d2.operator=(d1);// = 操作  双目：一个是对象本身，一个是赋值者
	d2.show();
	//要重载负号操作符
	Int d4 = -d1;
	d4.show();
	cout << !d4 << endl;
	Int d5;
	cout << !d5 << endl;
	++d5;
	++++d5;
	d5.show();
	Int d6 = d5++;
	cout << "_________________"<< endl;
	d5.show();
	d6.show();
	Int d7 = d5--;
	d5.show();
	d7.show();
	return 0;	
}

