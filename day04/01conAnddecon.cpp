#include <iostream>
using namespace std;


class A
{
public:
	int m_num;
	A(int num = 0):m_num(num)
	{
		cout << "A()" << endl;
	}
	~A(){cout << "~A()" << endl;}
};

class B
{
public:
	B(){cout << "B()" << endl;}
	~B(){cout << "~B()" << endl;}
};

class C
{
	B m_b;
	A m_a;
public:
	C(){cout << "C()" << endl;}
	~C(){cout << "~C()" << endl;}

};
int main()
{
	A a;
	cout << a.m_num << endl;
	a = A(6);
	cout << a.m_num << endl;

	return 0;	
}
