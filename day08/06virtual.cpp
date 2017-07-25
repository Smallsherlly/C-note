#include<iostream>
using namespace std;
class Animal
{
public:
	virtual void eat(){cout<<"eating"<<endl;}
	virtual void speak(){cout<<"speaking"<<endl;}
};
class Dog:public Animal
{
public:
	void eat(){cout<<"dog eat"<<endl;}
	void speak(){cout<<"dog speak"<<endl;}
};
class Cat:public Animal
{
public:
	void eat(){cout<<"cat eat"<<endl;}
	void speak(){cout<<"cat speak"<<endl;}
};
class Monkey:public Animal
{
	void eat(){cout<<"monkey eat"<<endl;}
	void speak(){cout<<"monkey speak"<<endl;}
};
class Tiger:public Animal
{
	void eat(){cout<<"tiger eat"<<endl;}
	void speak(){cout<<"tiger speak"<<endl;}
};
void show(Animal* animal)
{
	animal->eat();
	animal->speak();
}
int main()
{
	/*Animal* p=new Dog;
	p->eat();
	p->speak();
	p=new Cat;
	p->eat();
	p->speak();*/
	Animal* an[5]={new Dog(),new Cat(),new Monkey(),new Tiger(),new Dog()};
	for(int i=0;i<5;i++)
	{
		show(an[i]);
	}
	return 0;
}
