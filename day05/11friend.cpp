#include <iostream>
using namespace std;

//友元函数
class Person
{
private:
	string m_name;
	int m_age;
public:
	//声明一个全局函数为友元函数，友元函数可以访问类的私有属性
	//函数为全局函数，并不受类的访问控制属性控制
	friend void func(Person p);
	Person(const string& name = "",int age = 0):m_name(name),m_age(age){}

};
//不能写成void Person::func(Person p)
void func(Person p)
{
	cout << p.m_name << ":" << p.m_age << endl;
}

int main()
{
	Person p1("张三",33);
	func(p1);
	return 0;	
}
