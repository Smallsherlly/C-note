#include <iostream>
using namespace std;

class A
{
public:
	static int m_a;
	static void show(){
		cout << "静态函数" << m_a << endl;
	}
	
};

int A::m_a = 100;
int main()
{
	int *p = &A::m_a;
	cout << *p << endl;
	void (*pf)() = &A::show;
	(*pf)();
	return 0;	
}
