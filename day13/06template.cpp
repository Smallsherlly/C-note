#include <iostream>
using namespace std;

template<class T>
T fun(T x)
{
	cout << "T func(T x)" << endl;
}

int fun(double x)
{
	cout << "int func(int x)" << endl;
}

int main()
{
	fun(10);
	return 0;	
}
