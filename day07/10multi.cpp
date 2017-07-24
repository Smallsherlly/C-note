#include <iostream>
using namespace std;

class Animal
{
private:
	int m_age;
public:
	Animal(int age=0):m_age(age){}
	int getAge()
	{
		return m_age;
	}
	void show()
	{
		cout << "我是一个动物\n";
	}
};

class Mammal:public Animal
{
private:
	char m_sex;
public:
	Mammal(char sex='m',int age=0):Animal(age),m_sex(sex){}
	char getSex()
	{
		return m_sex;
	}
	void show()
	{
		cout << "我是一只哺乳动物\n";
	}
};

class Pig:public Mammal
{
private:
	float m_weight;
public:
	Pig(float weight,int age,char sex):Mammal(sex,age),m_weight(weight){}
	float getWeight()
	{
		return m_weight;
	}
	void show()
	{
		cout << "我是一只猪\n";
	}
};


int main()
{
	Pig p(200.0,10,'f');
	cout << p.getAge() << endl;
	cout << p.getSex() << endl;
	cout << p.getWeight() << endl;
	p.show();
	p.Mammal::show();
	p.Animal::show();
	Mammal m = p;
	m.show();
	Animal a = p;
	a.show();
	return 0;	
}
