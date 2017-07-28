#include <iostream>
#include <list>
using namespace std;

template<typename IT>
void print(IT begin,IT end)
{
	while(begin!=end)
		cout << *begin++ << " ";
	cout << endl;
}

bool compare(int a,int b)
{
	return a > b;
}
int main()
{
	list<int> l1 = {9,4,3,2};
	list<int> l2 = {8,7,6,1};
	l1.merge(l2,compare);
	print(l1.begin(),l1.end());
	return 0;	
}
