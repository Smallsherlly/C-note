#include <iostream>
using namespace std;

class Complex
{
private:
	int m_r;
	int m_v;
public:
	Complex(int r = 0,int v = 0):m_r(r),m_v(v){}
	Complex operator-(void)
	{
		return Complex(-m_r,-m_v);
	}
	Complex operator-(const Complex& other)
	{	
		return Complex(m_r - other.m_r,m_v - other.m_v);
	}
	Complex operator+(const Complex& other)
	{
		return Complex(m_r + other.m_r,m_v + other.m_v);
	}
	Complex operator*(const Complex& other)
	{
		return Complex(m_r * other.m_r - m_v * other.m_v,m_r * other.m_v+m_v* other.m_r);
	}
/*	Complex operator/(const Complex& other)
	{
		int 
		return Complex(m_r * other.m_r - m_v * other.m_v,m_r * other.m_v+m_v* other.m_r);
	}*/
	void show()
	{
		cout << m_r << "+" << m_v << "i" << endl;
	}

};

int main()
{
	Complex c1(3,4);
	Complex c2(1,2);
	Complex c3;
	c3 = c1 - c2;
	c3.show();
	return 0;	
}
