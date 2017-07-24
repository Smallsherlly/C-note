#include <iostream>
using namespace std;

class A
{
public:
	int m_a;
	A(int a=0):m_a(a){}
};
//中间类用virtual（虚拟类）
class B:virtual public A
{
public:
	B(int a=0):A(a){}
	void setA(int a)
	{
		m_a = a;
	}
};

class C:virtual public A
{
public:
	C(int a=0):A(a){}
	int getA()
	{
		return m_a;
	}

};

class D:public B,public C
{
public:
	//直接构造中间类的基类
	D(int a=0):B(a),C(a){}
};
int main()
{
	D d(100);
	//d.setA(9527);
	cout << d.getA() << endl;
	cout << d.B::m_a << endl;
	cout << d.C::m_a << endl;
	
	return 0;	
}
