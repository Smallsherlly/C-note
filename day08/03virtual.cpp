#include <iostream>
using namespace std;

class A
{
public:
	virtual void func(){cout<<"1"<<endl;}
	void func(int d){cout<<"2"<<endl}
	virtual void func()const{cout<<"7"<<endl;}
	int bar(){}

};

class B:public A
{
public:
	//void func(){cout<<"4"<<endl;}
	virtual void func(int d){cout<<"5"<<endl}
	void func()const{cout<<"8"<<endl;}
	int bar(){}
};

int main()
{
	A* pa = new B;
	pa->func();
	return 0;	
}



