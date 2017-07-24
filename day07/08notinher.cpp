#include <iostream>
using namespace std;

class A
{
private:
	int m_a;
	A(int a){m_a = a;}
	A(const A& that){}
	static A a;
public:
	static A& getInstance()
	{
		return a;
	}
	void show()
	{
		cout << m_a << endl;;	
	}
	friend class B;
};

A A::a(100);
class B:public A
{
public:
	B(int a):A(a){}

};

int main()
{
	A& a = A::getInstance();
	B b(200);
	a.show();
	b.show();
	return 0;	
}
