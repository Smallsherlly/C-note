#include <iostream>
using namespace std;


int main()
{
	int a = 10;
	int b = 5;
	const int* p1 = &a;
	int* p2 = &b;
	p2 = const_cast<int*>(p1);
	p1 = const_cast<const int*>(p2);

	return 0;
	
}
