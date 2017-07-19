#include <iostream>
using namespace std;


int main()
{
	int i = 19;
	int j = 9;
	int* p1 = &i;
	void* p2 = &j;
	p1 = static_cast<int*>(p2);
	p2 = static_cast<void*>(p1);
	
	return 0;	
}
