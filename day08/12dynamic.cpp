#include<iostream>
using namespace std;
class A
{
public:
	virtual void func(){cout<<"A"<<endl;}
};
class B:public A
{
public:
	void func(){cout<<"B"<<endl;}
};
class C:public A
{
public:
	void func(){cout<<"C"<<endl;}
};
class D
{
};
int main()
{
	A& pa=*new B;
	B& pb=dynamic_cast<B&>(pa);
	pb.func();
	//编译没问题，目标的实际类型和源类型不一致
	C& pc=dynamic_cast<C&>(pa);
	pc.func();
	A a;
	B b;
	//a=dynamic_cast<A>(b)
	D& d=*new D;
	A& ad=dynamic_cast<A&>(ad);
	return 0;
}
