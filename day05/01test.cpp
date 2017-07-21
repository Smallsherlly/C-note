#include <iostream>
using namespace std;

class Complex
{
private:
	int m_s;
	int m_x;
public:
	Complex(int s = 0,int x = 0):m_s(s),m_x(x){}
	Complex(const Complex& that)
	{
		m_s = that.m_s;
		m_x = that.m_x;
	}
	Complex& operator=(const Complex& that)
	{
		if(&that != this)
		{
			m_s = that.m_s;
			m_x = that.m_x;
		}
		return *this;
	}
	void show()
	{
		cout << m_s << "+" << m_x << "i" << endl;	
	}

	Complex operator-(void)
	{
		return Complex(-m_s,-m_x);
//		Complex temp(-m_d);
//		return temp;
	}
	bool operator!()
	{
		return (m_s==0&&m_x==0)?true:false;
	}
	Complex& operator++()
	{
		++m_s;
		return *this;
	}
	Complex operator++(int)
	{
		Complex t(m_s,m_x);
		++m_s;
		return t;
	}
	Complex& operator--()
	{
		--m_s;
		return *this;
	}
	Complex operator--(int)
	{
		Complex t(m_s,m_x);
		--m_s;
		return t;
	}
};

int main()
{
	Complex d1(3,4);
	d1.show();
	cout << "_________________"<< endl;
	Complex d2 = d1++;
	d1.show();
	d2.show();
	return 0;	
}

