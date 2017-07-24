#include <iostream>
using namespace std;

class A
{
public:
	int m_a;
	A(int a):m_a(a){}

};

class B:public A
{
public:
	B(int a):A(a){}
	void setA(int a)
	{
		m_a = a;
	}
	int getA()
	{
		return m_a;
	}
};

class C:public A
{
public:
	C(int a):A(a){}
	int getA()
	{
		return m_a;
	}

};


class D:public B,public C
{
public:
	D(int a):B(a),C(a){}

};

int main()
{
	D d(1);
	cout << d.B::getA() << endl;
	d.setA(100);
	cout << d.B::getA() << endl;
	return 0;	
}
