#include <iostream>
using namespace std;

void exchange1(int* a,int* b)
{
	int t = 0;
	t = *a;
	*a = *b;
	*b = t;
}

void exchange2(int &a,int &b)
{
	int t = 0;
	t = a;
	a = b;
	b = t;
}

int main()
{
	int a = 10,b = 5;
	exchange1(&a,&b);
	cout << a << " " << b << endl;
	
	exchange2(a,b);
	cout << a << " " << b << endl;

	return 0;
}
