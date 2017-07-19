#include <iostream>
using namespace std;


int main()
{
	int a = 10;
	int b;
	int* p1 = &a;
	b = reinterpret_cast<int>(p1);
	p1 = reinterpret_cast<int*>(b);

	return 0;
	
}
