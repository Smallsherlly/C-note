#include <iostream>
using namespace std;

template<typename T,typename K>
class A
{
public:
	void func(T t,K k)
	{
		cout << "func(T t,K k)" << endl;
	}
};

template<typename T,typename K>
class A<T*,K*>
{
public:
	void func(T* t,K* k)
	{
		cout << "func(T* t,K* k)\n";
	}
};

int main()
{
	A<int,double> a;
	a.func(10,20);
	A<int*,double*> b;
	int m = 10;
	double n = 20;

	b.func(&m,&n);
	return 0;
}
