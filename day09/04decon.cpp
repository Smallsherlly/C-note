#include <iostream>
using namespace std;

class A
{
public:
	A(){cout << "A()" << endl;}
	virtual ~A(){cout << "~A()\n";}
};

class B:public A
{
public:
	B(){cout << "B()" << endl;}
	~B(){cout << "~B()\n";}
};

int main()
{
	A* a = new B;
	delete a;//形成多态，动态绑定，调用子类的析构函数
	return 0;
}
