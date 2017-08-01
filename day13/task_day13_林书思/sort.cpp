#include <iostream>
using namespace std;

#define ARR_SIZE(a) (sizeof(a)/sizeof(a[0]))

#define swap(a,b) {a^=b;b^=a;a^=b;}

template<typename T>
const T& sort(T* a,size_t len)
{
	for(T* p1=a; p1<a+len-1; p1++)
	{
		for(T* p2=p1+1;p2<a+len;p2++)
		{
			if(*p2<*p1)
				swap(*p2,*p1);
		}
	}
}

template<typename K>
void show(K* a,size_t len)
{
	for(int i=0; i<len; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}

int main()
{
	int a[10] = {3,4,5,1,2,7,8,4,5,6};
	cout << ARR_SIZE(a) << endl;
	show(a,10);
	sort(a,10);
	show(a,10);
	char c[5] = {'c','t','y','u','g'};
	show(c,5);
	sort(c,5);
	show(c,5);
	return 0;
}
