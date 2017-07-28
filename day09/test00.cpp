#include <iostream>
#include <fstream>

using namespace std;

class Person
{
public:
	string m_name;
	int m_age;
public:
	Person(const string& name="",int age=123):m_name(name),m_age(age){}
	friend ostream& operator<<(ostream& os,const Person& p);
	friend istream& operator>>(istream& is,Person& p);
	
};
ostream& operator<<(ostream& os,const Person& p)
{
	return os << p.m_name << ":" << p.m_age;
}
istream& operator>>(istream& is,Person& p)
{
	return is >> p.m_name >> p.m_age;
}

int main()
{

	ofstream fout("./b.txt");
	Person p("张飞",33);
	if(fout)
	{
		fout << p;
	}
	fout.close();
	ifstream fii("./b.txt");
	
	Person p1;
	if(fii)
	{
		fii >> p1;
	}
	cout << p1;
	cout << p1.m_name << endl;
	cout << p1.m_age << endl;
	return 0;	
}
