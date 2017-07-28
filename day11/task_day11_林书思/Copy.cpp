#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;


class bt
{
public:
	string m_name;
	string m_dm;
	string m_zb;
	string  m_day;
	string m_am;
	bt(){}
	bt(const string& name,const string& dm,const string& zb,const string& day,const string& am){}
	friend ostream& operator<<(ostream& os,const bt& p);
	friend istream& operator>>(istream& is,bt& p);
};

ostream& operator<<(ostream& os,const bt& p)
{
	return os << p.m_name << " " << p.m_dm << " " << p.m_zb << " " << p.m_day << " " << p.m_am << endl;
}
istream& operator>>(istream& is,bt& p)
{
	return is >> p.m_name >> p.m_dm >> p.m_zb >> p.m_day >> p.m_am;
}
class pf
{
public:
	string m_name;
	double m_dm;
	string m_zb;
	int  m_day;
	double m_am;
	pf(){}
	pf(const string& name,double dm,const string& zb,int day,double am){}
	friend ostream& operator<<(ostream& os,const pf& p);
	friend istream& operator>>(ostream& is,pf& p);
	friend bool operator<(const pf& p1,const pf& p2);
};
bool operator<(const pf& p1,const pf& p2)
{
	return p1.m_am > p2.m_am;
}
ostream& operator<<(ostream& os,const pf& p)
{
	return os << p.m_name << " " << p.m_dm << " " << p.m_zb << " " << p.m_day << " " << p.m_am << endl;
}
istream& operator>>(istream& is,pf& p)
{
	return is >> p.m_name >> p.m_dm >> p.m_zb >> p.m_day >> p.m_am;
}


int main()
{
	vector<pf> p;
	pf p1;
	bt b;
	ifstream fin("./pf.txt");
	ofstream fout("./pfcopy.txt");
	
	if(fin&&fout)
	{
		fin >> b;
		fout << b;
		cout << b;
		while(fin >> p1)
		{
			p.push_back(p1);
		}
	}
	sort(p.begin(),p.end());
	vector<pf>::iterator it = p.begin();

	for(;it!=p.end();it++)
	{
		fout << *it;
		cout << *it;
	}
	fin.close();
	fout.close();
};
