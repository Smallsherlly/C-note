#include <iostream>
using namespace std;

class A
{
public:
	A()
	{
		cout << "Begin" << endl;
	}
	~A()
	{
		cout << "End" << endl;
	}
};

A a;

int main()
{
	cout << "main()" << endl;
	return 0;	
}



