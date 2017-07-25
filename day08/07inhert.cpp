#include<iostream>
using namespace std;
class A
{
public:
	void func(){cout<<"A::func"<<endl;}
	virtual void bar(){cout<<"virtual A::bar"<<endl;}
};
class B:public A
{
public:
	void func(){cout<<"B::func"<<endl;}
	virtual void bar(){cout<<"B::bar"<<endl;}
};
int main()
{
	A a;//肯定是调用A类方法
	B b;//肯定是调用B类方法
	A* p=new B;//父类指针指向子类对象
	p->func();//A的
	p->bar();//B的，虚函数
	return 0;
}
