#include <iostream>
#include <vector>
using namespace std;


int main()
{
	//使用vector的第一步，确定存储数据的类型
	//从类模板实例化了一个模板类
	vector<int>	v1;//实例化了一个对象
	cout << v1.size() << endl;
	v1.resize(10,1);
	cout << v1.size() << endl;
	for(int i=0; i<v1.size(); i++)
	{
		cout << v1.at(i) << " ";
	}
	cout << endl;
	vector<int> v2(10,100);
	cout << v2.size() << endl;
	for(int i=0; i<v2.size(); i++)
	{
		cout << v2.at(i) << " ";
	}
	cout << endl;
	vector<int> v3 = v2;
	cout << v3.size() << endl;
	for(int i=0; i<v3.size(); i++)
	{
		cout << v3.at(i) << " ";
	}
	cout << endl;
	int arr[10] = {0,1,2,3,4,5,6,7,8,9};
	vector<int> v4(&arr[0],&arr[9]);
	cout << v4.size() << endl;
	for(int i=0; i<v4.size(); i++)
	{
		cout << v4.at(i) << " ";
	}
	cout << endl;
	vector<int> v5;
	v5.reserve(10);
	cout << v5.size() << endl;
	return 0;	
}
