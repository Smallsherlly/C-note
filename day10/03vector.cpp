#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int> v1;
	for(int i=1; i<=10; i++)
	{
		v1.push_back(i*i);
	}
	vector<int>::iterator it = v1.begin();
	for(; it!=v1.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
	vector<int>::reverse_iterator it1 = v1.rbegin();

	for(it1=v1.rbegin(); it1!=v1.rend(); it1++)
	{
		cout << *it1 << " ";
	}
	cout << endl;
	it = v1.begin();
	v1.insert(it,199);
	cout << "return:" << *it << endl;
	it = v1.end();
	v1.insert(it,110);
	for(it=v1.begin(); it!=v1.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
	it = v1.begin();
	it = it+4;
	v1.insert(it,5,9527);
	for(it=v1.begin(); it!=v1.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
	it = v1.begin();
	it = it+5;
	int arr[10] = {0,1,2,3,4,5,6,7,8,9};
	v1.insert(it,&arr[0],&arr[9]);
	for(it=v1.begin(); it!=v1.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
	it = v1.begin();
	it = it+4;
	it = v1.erase(it);
	for(it=v1.begin(); it!=v1.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
	it = v1.begin();
	it = it+4;
	vector<int>::iterator it2 = v1.begin();
	it2 = it2 +6;
	it = v1.erase(it,it2);
	cout << "return:" << *it << endl;
	for(it=v1.begin(); it!=v1.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
	return 0;	
}
