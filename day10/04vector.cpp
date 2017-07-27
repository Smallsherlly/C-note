#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int> v1 = {1,2,3,4};
	vector<int> v2 = {3,4,5,6,7};
	vector<int> v3 = {3,4,5,6,7,8,9};
	vector<int> v4 = {3,4,5,6,7,8,9,2};
	vector<vector<int>> v5={v1,v2,v3,v4};
	for(int i=0; i<v5.size(); i++)
	{
		vector<int>& v = v5.at(i);//用引用节省开销
		for(int j=0; j<v.size(); j++)
		{
			cout << v.at(j);
		}
		cout << endl;
	}
	vector<vector<int>>::iterator it = v5.begin();
	for(; it!=v5.end(); it++)
	{
		vector<int>::iterator iti = it->begin();
		for(; iti!=it->end(); iti++)
		{
			cout << *iti << " ";
		}
		cout << endl;
	}
	return 0;
}
