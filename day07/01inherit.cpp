#include <iostream>
using namespace std;

class Person
{
protected:
	string m_name;
	int m_age;
public:
	Person(const string& name="",int age=0):m_name(name),m_age(age){}
	void show()
	{
		cout << m_name << ":" << m_age << endl;
	}
};

class Student:public Person
{
private:
	int m_id;
public:
	void show()
	{
		cout << m_id << endl;
		cout << m_name << ":" << m_age << endl;
	}
};

class Teacher:public Person
{
private:
	float m_salary;
public:
	Teacher(int salary=0):m_salary(salary){}
	void show()
	{
		cout << m_salary << endl;
	}
	
};

int main()
{
	Person p1("张三",33);
	Student s1;
	Teacher t1(5000);
//	p1 = s1;//Student 是Person
	//s1 = p1;
	Student& s2 = static_cast<Student&>(p1);
	Student* s3 = static_cast<Student*>(&p1);
	p1.show();
	s1.show();
	t1.show();
	s2.show();
	s3->show();
	return 0;	
}
