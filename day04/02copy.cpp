#include <iostream>
using namespace std;

class Person
{
	string m_name;
	int m_age;
public:

	Person(const string& name="",int age=0):m_name(name),m_age(age)
	{
		cout << "构造函数" << endl;
	}
	Person(const Person& that):m_name(that.m_name),m_age(that.m_age)
	{
		cout << "拷贝构造函数" << endl;
	}

};

//引用和指针不会调用拷贝构造函数
void func1(Person p)
{
	
}

Person func2()
{
	Person p = Person("qw",33);
	return p;
}
int main()
{
	Person p1 = Person("张飞",33);
	Person p2 = p1;//拷贝构造
	Person p3(p1);//拷贝构造
	Person p4;//无参构造
//	p4 = p1;//拷贝赋值
	cout << "+++++++++\n";
	func1(p1);//在函数调用时，实参拷贝构造了形参p
	cout << "+++++++++\n";
	cout << "---------\n";
	func2();
	cout << "---------\n";
//	Person *p6 = new Person[4]{p1,p2,p3,p4}
	return 0;	
}
