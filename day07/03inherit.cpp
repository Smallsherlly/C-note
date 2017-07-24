#include <iostream>
using namespace std;

class A
{
public:
	int m_a;
	int m_b;
	A(int a=1,int b=3):m_a(a),m_b(b){}

};

class B:public A
{
public:
	int m_a;
	B(int a=2):m_a(a){}
	void print()
	{
		//访问父类中同名的标识符
		cout << A::m_a << endl;
	}
};


int main()
{
	B b;
	cout << b.m_a << endl;
	cout << b.m_b << endl;
	cout << b.A::m_a << endl;
	b.print();
	return 0;	
}
