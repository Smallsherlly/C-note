#include <iostream>
using namespace std;

class A
{
public:
	A(){cout << "A" << endl;}

};

class B
{
public:
	B(){cout << "B" << endl;}
};

class C
{
public:
	C(){cout << "C" << endl;}
};

class D
{
public:
	D(){cout << "D" << endl;}
};

class F:public B,public A
{
private:
	D d;
	C c;
public:
	F()
	{
		cout << "F\n";
	}
};

int main()
{
	F f;
	return 0;	
}


