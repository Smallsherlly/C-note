#include <iostream>
#include <typeinfo>
using namespace std;

class A
{
	virtual void func()
	{
		cout << "A\n";
	}
};

class B:public A
{
	void func()
	{
		cout << "B\n";
	}
};


int main()
{
	int a = 10;
	int *p = &a;
	cout << typeid(a).name() << endl;
	cout << typeid(p).name() << endl;
	A* pa = new B;
	//可以求多态时对象的真实类型
	cout << typeid(*pa).name() << endl;
	
	return 0;
}
