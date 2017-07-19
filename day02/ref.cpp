#include <iostream>
using namespace std;

void swap(int* a,int* b)
{
	int t = 0;
	t = *a;
	*a = *b;
	*b = t;
}

int swap(int &a,int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

//函数的参数在调用时进行初始化
int main()
{
	int a = 10;
	int b = 5;
	swap(a,b);
	cout << a << endl;
	cout << b << endl;
	return 0;	
}
