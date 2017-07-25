#include <iostream>
using namespace std;

class A
{
public:
	virtual void func()throw(int,string)
	{
		cout<<"A::func"<<endl;	
	}
};

class B:public A
{
public;
	void func()throw(int)
	{
		cout<<"B::func"<<endl;
	}

};

int main()
{
	A *p = new B;
	p->func();

}
