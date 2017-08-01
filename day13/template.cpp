#include <iostream>
using namespace std;


template<typename T,class F>
int compare(const T& a,const F& b)
{
	if(a>b) return 1;
	if(a<b) return -1;
	return 0;
}

int main()
{
	int a = 10;
	double b = 80;
	cout << compare(a,b);
	return 0;	
}
