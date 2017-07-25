#include<iostream>
using namespace std;
class A
{
public:
	virtual void func(){}
	void bar(){}
};
class B:public A
{
public:
	void func(){}
};
class D
{
	virtual void goo(){}
};
class F
{
	virtual void foo(){}
};
class E:public D,public F
{
};
int main()
{
	cout<<sizeof(B)<<endl;
	cout<<sizeof(E)<<endl;
	return 0;
}
