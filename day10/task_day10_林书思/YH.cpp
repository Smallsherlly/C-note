#include <iostream>
#include <vector>
using namespace std;


int main()
{
	//保存杨辉三角形
	vector<int> v1 = {1};
	vector<int> v2 = {1,1};
	vector<int> v3,v4,v5,v6,v7;
	vector<vector<int>> v = {v1,v2,v3,v4,v5,v6,v7}; 
	for(int i=2; i<v.size(); i++)
	{
		vector<int>& s = v.at(i);
		for(int j=0; j<i; j++)
		{
			if(j==0||j==i-1)
				s.push_back(1);
			else
			s.push_back(v.at(i-1).at(j)+v.at(i-1).at(j-1));
		}
	}
	for(int i=0; i<v.size(); i++)
	{
		vector<int> s = v.at(i);
		for(int j=0; j<s.size(); j++)
		{
			cout << s.at(j) << " ";
		}
		cout << endl;
	}
}
