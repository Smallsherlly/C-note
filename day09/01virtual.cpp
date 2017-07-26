#include <iostream>
using namespace std;

class A
{
public:
	//纯虚函数的声明必须这样，virtual=0
	virtual void func()=0;

};
//纯虚函数必须在类外定义
void A::func()
{
	cout << "A::func" << endl;
}

class B:public A
{
	void func()
	{
		cout << "B::func" << endl;
	}
};

void test(A& a)
{
	a.func();
}

int main()
{
	B b;
	test(b);
	return 0;	
}
