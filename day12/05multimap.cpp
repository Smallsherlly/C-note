#include <iostream>
#include <map>
using namespace std;


int main()
{
	multimap<string,double> mm;

	mm.insert(pair<string,double>("刘备",1000));
	mm.insert(pair<string,double>("刘备",3000));
	mm.insert(pair<string,double>("关羽",5000));
	mm.insert(pair<string,double>("关羽",2000));
	mm.insert(pair<string,double>("张飞",4000));
	mm.insert(pair<string,double>("张飞",6000));
	mm.insert(pair<string,double>("刘备",2500));

	typedef map<string,double>::iterator IT;
	pair<IT,IT> itpair = mm.equal_range("刘备");
	double account = 0;
	for(IT it = itpair.first;it!=itpair.second;it++)
	{
		account += it->second;
	}
	cout << account << endl;
	cout << "----------------\n";
	IT it = mm.begin();
	for(;it!=mm.end();)
	{
		pair<IT,IT> itpair = mm.equal_range(it->first);
		double mount = 0;
		for(IT itt=itpair.first;itt!=itpair.second;itt++)
		{
			mount += itt->second;
		}
		cout << it->first << "总业绩：" << mount << endl;
		it = itpair.second;//如何跳过相同的key
	}
	return 0;
}
