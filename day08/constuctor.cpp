#include<iostream>
using namespace std;
class A
{
public:
	virtual void func()
	{
		cout<<"A::func()"<<endl;
	}
	A(){func();}
	~A(){cout<<"～";func();}
	void bar(){func();}//多态时调用的是子类的方法
};
class B:public A
{
public:
	void func()
	{
		cout<<"B::func()"<<endl;
	}
};
int main()
{
	A* pa=new B;
	//pa->bar();
	delete pa;
	return 0;
}
