#include <iostream>
using namespace std;

class Person
{
// 类的访控属性
public:
	// 类的属性，也叫成员
	char sex;
	int age;
	char name[24];
	float height;
	double weight;
	// 方法
	Person(char s,float h,double w,int a,char* n)
	{
		cout << "" << endl;
		sex = s;
		height = h;
		weight = w;
		age = a;
		strcpy(name.n);
	}
	void eating()
	{	
		cout << "睡醒了吃～" << endl;	
	}

	void sleeping()
	{
		cout << "吃饱了睡～" << endl;	
	}
};

int main()
{
	// 类对象不可以使用{}初始化
	Person p('m',0.5,256,18,const_cast<char*>("silence"));
	p.eating();
	return 0;	
}
