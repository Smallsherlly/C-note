#include <iostream>
using namespace std;

class Complex
{
private:
	int m_s;
	int m_x;
public:
	Complex(int s=0,int x=0):m_s(s),m_x(x){}
	Complex(const Complex& that):m_s(that.m_s),m_x(that.m_x){}
	Complex operator=(const Complex& that)
	{
		if(&that != this)
		{
			m_s = that.m_s;
			m_x = that.m_x;
		}
		return *this;
	}

	Complex& operator+=(const Complex& that)
	{
		m_s = m_s + that.m_s;
		m_x = m_x + that.m_x;
		
		return *this;
	}
	Complex& operator-=(const Complex& that)
	{
		m_s = m_s - that.m_s;
		m_x = m_x - that.m_x;
		
		return *this;
	}
	Complex operator+(const Complex& that)
	{
		return Complex(m_s+that.m_s,m_x+that.m_x);
	}
	Complex operator-(const Complex& that)
	{
		return Complex(m_s-that.m_s,m_x-that.m_x);
	}
	Complex operator-()
	{
		return Complex(-m_s,-m_c);
	}
	void show()
	{
		cout << m_s << "+" << m_x << "i" << endl;
	}
};

int main()
{
	Complex c1(4,6);
	Complex c2(3,3);
	Complex c3;
	c3 = c1;
	c3.show();
	c3 += c1;
	c3.show();
	c3 -= c1;
	c3.show();
	(c1-c2).show();
	return 0;
}
