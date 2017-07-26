#include <iostream>
#include <fstream>
//#include <if
using namespace std;

class Person
{
private:
	string m_name;
	int m_age;
public:
	Person(const string& name="",int age=0):m_name(name),m_age(age){}
	friend ostream& operator<<(ostream& os,const Person& p);
	friend istream& operator>>(istream& is,Person& p);
	
};
ostream& operator<<(ostream& os,const Person& p)
{
	return os << p.m_name << " " << p.m_age;
}
istream& operator>>(istream& is,Person& p)
{
	return is >> p.m_name >> p.m_age;
}

int main()
{
	ofstream of("./a.txt",ios::out);
	of << "Hello";
	of.close();
	ifstream iff("./a.txt",ios::in);
	string str;
	iff >> str;
	cout << str << endl;
	ifstream fin("./b.txt");
	if(!fin)
	{
		cout << "打开文件失败" <<endl;
	}
	ofstream fout("./b.txt");
	int x = 10;
	char c = 'a';
	double d = 3.14;
	Person p("张飞",33);
	if(fout)
	{
		fout << x << c << d;
		fout << p;
	}
	fout.close();
	ifstream fii("./b.txt");
	int x1 = 0;
	char c1 = '0';
	double d1 = 0;
	Person p1;
	if(fii)
	{
		fii >> x1 >> c1 >> d1;
		fii >> p1;
	}
	cout << x1 << ":" << c1 << ":" << d1 << endl;
	cout << p1;
	fii.close();
	fstream f("./b.txt",ios::in|ios::out);
	int x2 = 0;
	char c2 = '0';
	double d2 = 0.0;
	Person p2;
	if(f)
	{
		f>>x2>>c2>>d2>>p2;
	}
	cout << x2 << c2 << d2 << p2;
	int temp = f.tellg();
	int i = 0;
	f<<123;
	f.close();
	char str2[24];
	f.seekg(-4,ios::cur);
	f>>i;
	cout<< i;

	return 0;	
}
