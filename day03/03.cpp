#include <iostream>
using namespace std;

class Person
{
	string m_name;
	int m_age;
public:
	Person(const string& name = "",int age=0):m_name(name),m_age(age)
	{
		
	}
	
	const string& getName()
	{
		return m_name;
	}
	int getAge()
	{
		return m_age;
	}
	void show(){
		cout << getName() << ":" << getAge() << endl;
	}
};

int main()
{
	Person p1;
	p1.show();
	Person p2("张飞");
	p2.show();
	Person p3("张飞",33);
	p3.show();
	Person p4 = Person();
	p4.show();

	

	return 0;	
}
