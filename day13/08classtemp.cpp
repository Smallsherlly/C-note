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
};

template<>
class Comparator<const char*>
{
public:
	 const char* const& compare(const char* const& x,const char* const& y)
	{
		cout << "特化版本" << endl;
		return strcmp(x,y)>0?x:y;
	}
};

int main()
{
	Comparator<const char*> com;
	cout << com.compare("hello","world") << endl;
	Comparator<int> c1;
	cout << c1.compare(1,4) << endl;
	return 0;
}
