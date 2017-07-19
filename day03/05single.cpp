#include <iostream>
using namespace std;

class Person
{
	string m_name;
	int m_age;
public:
	Person(){};
	Person(const string& name,int age)
	{
		m_name = name;
		m_age = age;
	}
	Person(int age)
	{
		m_age = age;
		m_name = string("无名");
	}
	void show()
	{
		cout << m_name << ":" << m_age <<endl;
	}

	operator int()
	{
		return m_age;
	}
};

int main()
{
	Person p1 = Person(5);
	p1.show();
	Person p2 = 10;
	p2.show();
	int num = p2;

	return 0;
}
