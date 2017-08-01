#include <iostream>
#include <set>
#include <vector


using namespace std;



int main()
{
	
	vector<int> v= {1,7,2,3,3,2,5,6,4};//去重
	set<int> s;
	vector<int>::iterator it = v.begin();

	for(;it!=v.end();it++)
	{
		s.insert(*it);
	}
	set<int>::iterator iter = s.begin();
	for(;iter!=s.end();iter++)
	{
		cout << *iter << " ";
	}
	cout << endl;
	
	vector<int> v1 = {1,2,3,2,3,4,5};
	vector<int> v2 = {2,4,5,2,5};
	s.clear();
	set<int> s2;
	it = v1.begin();
	for(;it!=v1.end();it++)
	{
		s.insert(*it);
	}
	it = v2.begin();
	typedef set<int>::iterator IT;
	pair<IT,int> sp;
	for(;it!=v2.end();it++)
	{
		sp = s.insert(*it);
		if(false==sp.second)
			s2.insert(*it);
	}
	cout << endl;
	for(iter=s2.begin();iter!=s2.end();iter++)
	{
		cout << *iter << " ";
	}
	cout << endl;


	return 0;	
}
