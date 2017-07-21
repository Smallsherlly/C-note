#include <iostream>
using namespace std;

class Person
{
public:
	string m_name;
	int m_age;

	Person(const string& name,int age):m_name(name),m_age(age)
	{

	}
	
	void show()
	{
		cout << m_name << ":" << m_age << endl;
	}
	
	void print(int num)
	{
		cout << "我是你爹，我有一个参数num：" << num << endl;
	}
};

int main()
{
	// 定义一个成员指针,指向m_age这个成员
	int Person::*p_age = &Person::m_age;
	Person p1("张飞",22);
	cout << p1.*p_age << endl;
	Person p2("李四",44);
	cout << p2.*p_age << endl;
	string Person::*p_name = &Person::m_name;
	cout << p1.*p_name << endl;
	cout << p2.*p_name << endl;
	cout << p_age << endl;
	cout << p_name << endl;
	void (Person::*p)() = &Person::show;
	(p1.*p)();
	void (Person::*pf)(int) = &Person::print;
	(p1.*pf)(3);
}
