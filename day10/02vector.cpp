#include <iostream>
#include <vector>
#include <algorithm>
//sort()
using namespace std;


int main()
{
	vector<int> v1 = {0,1,2,3,4,5,6,7,8,9};//c++0x
	for(int i=0; i<v1.size(); i++)
	{
		cout << v1.at(i) << " ";
	}
	cout << endl;
	v1.reserve(100);
	cout << v1.max_size() << endl;
	vector<int> v2;
//	v2.reserve(10);
	v2.assign(10,100);
	cout << v2.size() << endl;
	for(int i=0; i<v2.size(); i++)
	{
		cout << v2.at(i) << " ";
	}
	cout << endl;
	v2.resize(15,200);
	for(int i=0; i<v2.size(); i++)
	{
		cout << v2.at(i) << " ";
	}
	cout << endl;
	v2.push_back(3);
	cout << v2.front() << endl;
	cout << v2.back() << endl;
	v2.pop_back();
	cout << v2.back() << endl;
/*	v2.clear();
	cout << v2.size() << endl;
	if(v2.empty())
	{
		cout << "vector is empty" << endl;
	}
	else
	{
		cout << "vector is not empty" << endl;
	}
	v2.reserve(10);
	cout << v2.size() << endl;
	if(v2.empty())
	{
		cout << "vector is empty" << endl;
	}
	else
	{
		cout << "vector is not empty" << endl;
	}*/
	vector<int> v3;
	for(int i=0; i<10; i++)
	{
		v3.push_back(i*i);
	}
	cout << v3.front() << endl;
	v3.front() = 98;
	v3.back() = 45;
	for(int i=0; i<v3.size(); i++)
	{
		cout << v3.at(i) << " ";
	}
	cout << endl;
	sort(v3.begin(),v3.end());
	for(int i=0; i<v3.size(); i++)
	{
		cout << v3.at(i) << " ";
	}
	cout << endl;
	return 0;	
}
