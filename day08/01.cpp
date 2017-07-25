#include <iostream>
using namespace std;

class A
{
public:
	virtual void func()
	{
		cout << "A::virtual void fun()" << endl;
	}
	void bar()
	{
		cout << "A::bar()" << endl;
	}
};

class B:public A
{
public:
	void func()//覆盖A类中的func函数
	{
		cout << "B::virtual void func()\n";
	}
	void bar()//隐藏A类中的bar函数
	{
		cout << "B::bar()\n";
	}

};

int main()
{
	A a;
	a.func();
	a.bar();
	B b;
	b.func();
	b.bar();
	A* pa = new B;
	pa->func();
	pa->bar();
	return 0;	
}
