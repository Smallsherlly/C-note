//内存与构造的顺序关系
#include <iostream>
#include <cstdlib>
using namespace std;

class Int
{
private:
	int m_data;	
public:
	Int(int d=0):m_data(d)
	{
		cout << "构造函数" << m_data << endl;	
	}
	//分配内存空间
	static void* operator new(size_t size)
	{
		cout << "operator new\n";
		void *p = malloc(size);
		return p;
	}
	static void* operator new[](size_t size)
	{
		cout << "new []\n";
		return malloc(size);
	}
	~Int(void)
	{
		cout << "析构函数" << m_data << endl;
	}
	static void operator delete(void *p)
	{
		cout << "operator delete\n";
		free(p);
	}
	static void operator delete[](void *p)
	{
		cout << "delete[]\n";
		free(p);
	}
};

int main()
{
	Int *ip = new Int(100);
	delete ip;
	Int ip2(200);
	Int *ip1 = new Int[10]{0,1,2,3,4,5,6,7,8,9};
	int i=0;
//	for(; i<10; i++)
//		*(ip1+i) = i;
	delete [] ip1;
	return 0;	
}
