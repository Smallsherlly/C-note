#include <iostream>
using namespace std;

class A
{
private:
	int a;
protected:
	int b;
public:
	int c;
};

class B:private A
{
public:
	void show()
	{
	//	cout << a << endl;//private不可以访问
		cout << b << endl;
		cout << c << endl;
	}
};

class C:public B
{
	void printf()
	{
		cout << b << endl;
		cout << c << endl;
	}
};

int main()
{
	
	return 0;	
}
