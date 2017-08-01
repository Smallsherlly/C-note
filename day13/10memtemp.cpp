#include <iostream>
#include <cstring>
using namespace std;

template<typename T>
class Comparator
{
public:
	const T& compare(const T& x,const T& y)
	{
		return x>y?x:y;
	}
	
	//只有某些成员函数需要特化时
//	const char* compare(const char*,const char*);
	
	template<const char*>
	const char* compare(const char* x,const char* y)
	{
		cout << "特化版本\n";
		return strcmp(x,y)>0?x:y;
	}

	void fun()
	{
		cout << "fun()\n";
	}		
};
/*
template<>
const char* const& Comparator<const char*>::compare(const char* const& x,const char* const& y)
{
	cout << "特化版本\n";
	return strcmp(x,y)>0?x:y;
}
*/
int main()
{
	Comparator<int> co;
	co.compare(1,20);
	co.fun();
	Comparator<const char*> cc;
	cout << cc.compare("hello","world") << endl;
	cc.fun();
	return 0;
}
