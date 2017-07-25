#include <iostream>
using namespace std;

class A
{
public:
	virtual void func()
	{
		cout << "A func()" << endl;
	}
};

class B:public A
{
public:
	virtual void func()
	{
		cout << "B func()" <<endl;
	}

};

int main()
{
	B b;
	b.func();
	b.A::func();
	A& a = b;
	a.func();
	return 0;	
}
