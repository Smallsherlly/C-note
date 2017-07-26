#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

class Person
{
public:
	char m_name[24];
	int m_age;
public:
	Person(const char* name="",int age=0)
	{
		strcpy(m_name,name);
		m_age = age;
	}
	~Person(){}

};
int main()
{
	int a = 100;
	char c = 'x';
	double d = 3.14;
	fstream f("./c.txt",ios::in|ios::out|ios::trunc);
	if(f)
	{
		f<<a<<c<<d;
	}
	
	int a1 = 0;
	char c1 = '0';
	double d1 = 0;
	f.seekg(0,ios::beg);//设置文件流位置
	if(f)
	{
		f>>a1>>c1>>d1;
	}
	cout << a1 << c1 << d1<<endl;
	f.close();
	Person p("张飞",33);
	fstream ff("./d.txt",ios::in|ios::out|ios::trunc);
	if(ff)
	{
		ff.write((const char*)&p,sizeof(p));
	}
	ff.seekg(0,ios::beg);
	Person p1;
	ff.read((char*)&p1,sizeof(p));
	cout<<p1.m_name<<p1.m_age<<endl;
	ff.close();
	return 0;	
}
