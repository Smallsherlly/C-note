#include <iostream>
using namespace std;



int main()
{
	//隐式类型转换
	/*
	int n = 'a';	
	short s = 123;
	n = s;
	char c = n;
	void *p = &n;
	int *pi = p;
	*/
	int n = 100;
	char a = 'x';
	a = static_cast<char>(n);
	cout << a << endl;
	n = static_cast<int>(a);

	void* p = static_cast<void*>(&n);
	int *pi = static_cast<int*>(p);
	p = static_cast<void*>(&a);
	char*pv = static_cast<char*>(p);
	return 0;	
}
