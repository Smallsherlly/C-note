#include <iostream>
#include <map>

using namespace std;


int main()
{
	map<int,string> p;

	typedef map<int,string>::iterator IT;

	pair<IT,bool> ret;
	
	ret = p.insert(pair<int,string>(0,"张飞"));
	if(ret.second)
	{
		cout << ret.first->first<<":"<<ret.first->second<<endl;
	}
	p.insert(pair<int,string>(0,"张飞"));
	p.insert(pair<int,string>(1,"李白"));
	ret = p.insert(pair<int,string>(0,"张飞"));
	if(ret.second)
	{
		cout << ret.first->first<<":"<<ret.first->second<<endl;
	}
	else
		cout << "NO\n";
	
	ret = p.insert(make_pair(1,"lin"));
	cout << p.size() << endl;
	//返回一个迭代其和一个bool类型组成的pair，如果成功插入，则bool结果为true，迭代器指向为插入的元素，如果失败，则bool的值为false，迭代器指向为空
	for(IT it = p.begin(); it!=p.end();it++)
	{
		cout << it->first <<":" << it->second << "\n";
	}
	cout <<"_________\n";
	IT it = p.find(1);
	if(it!=p.end())
	{
		cout << it->first<<":"<<it->second<<endl;
	}

	return 0;
}
