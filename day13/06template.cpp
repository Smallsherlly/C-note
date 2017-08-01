#include <iostream>
using namespace std;

template<class T,size_t index>
T fun(T x[])
{
	cout << "T func(T x)" << endl;
}
/*
int fun(double x)
{
	cout << "int func(int x)" << endl;
}
*/
int main()
{
	int a[4] = {1,2,3,4};
	fun<int,4>(a);
	return 0;	
}
