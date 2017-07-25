#include <iostream>
using namespace std;
class A{};
class B:public A{};

class Base
{
public:
	virtual	A* func(){cout<<"Base func"<<endl;}
	virtual void show()
	{
		cout<< "@@" <<endl;
	}
};

class Dived:public Base
{
public:
	B* func(){cout<<"Dived func"<<endl;}
};
typedef void(*fun)(void);

int main()
{
	Base *pd = new Dived;
	fun f = (fun)*((int*)*(int*)pd+1);
	(*f)();
	pd->func();
	fun f = (fun)*((int*)*(int*)pd+1);
	(*f)();
	pd->func();
	return 0;
}
