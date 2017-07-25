#include <iostream>
using namespace std;

class Person
{
private:
	string m_name;
	int m_age;
public:
	Person(const string& name="",int age=0):m_name(name),m_age(age){}
	const string& getName()
	{
		return m_name;	
	}
	int getAge()
	{
		return m_age;	
	}
};

class Student:virtual public Person
{
private:
	int m_id;
public:
	Student(){}
	Student(const string& name,int age,int id):Person(name,age),m_id(id){}
	void Study()
	{
		cout<< getName() << ":" << getAge() << ":" << m_id << endl;
		cout << "我爱学习～\n";	
	}

};

class Teacher:virtual public Person
{
private:
	int m_salary;
public:
	Teacher(){}
	Teacher(const string& name,int age,int salary):Person(name,age),m_salary(salary){}
	void Teach()
	{
		cout<< getName() << ":" << getAge() << ":" << m_salary << endl;
		cout << "我爱教书～\n";	
	}

};

class Tutor:public Student,public Teacher
{
public:
	Tutor(const string& name,int age):Person(name,age){}

};

int main()
{
	Student s("小林",18,56);
	Teacher t("小婷",28,10000);
	s.Study();
	t.Teach();
	Tutor tt("猪哥",99);
	cout << tt.getName() << ":" << tt.getAge() << endl;
	cout << tt.Student::getName() << endl;
	cout << tt.Teacher::getName() << endl;
	return 0;	
}
