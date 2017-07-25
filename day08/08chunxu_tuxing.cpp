#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;
class Shape
{
public:
	virtual double area()=0;//定义一个纯虚函数
	virtual double len()=0;
};
class Retangle:public Shape
{
	int m_w;
	int m_h;
public:
	Retangle(int w,int h):m_w(w),m_h(h){cout<<"Retangle"<<":"<<w<<":"<<h<<endl;}
	double area()
	{
		return m_w*m_h;
	}
	double len()
	{
		return 2*(m_w+m_h);
	}
};
class Circle:public Shape
{
	int m_r;
public:
	Circle(int r):m_r(r){cout<<"Circle"<<":"<<r<<endl;}
	double area()
	{
		return 3.14*m_r*m_r;
	}
	double len()
	{
		return 6.28*m_r;
	}
};
class Triggle:public Shape
{
	int m_l1;
	int m_l2;
	int m_l3;
public:
	Triggle(int l1,int l2,int l3):m_l1(l1),m_l2(l2),m_l3(l3){cout<<"Triggle"<<l1<<":"<<l2<<":"<<l3<<endl;}
	double area(){return 0;}
	double len(){return m_l1+m_l2+m_l3;}
};
Shape& maxLen(Shape* (&arr)[10])
{
	Shape* pmax=arr[0];
	for(int i=1;i<10;i++)
	{
		if(pmax->len() < arr[i]->len())
		{
			pmax=arr[i];
		}
	}
	return *pmax;
}
//Shape& maxLen(Shape **arr)
int main()
{
	//Shape s;抽象类不可以实例化对象
	Retangle r1(10,10);
	Shape* arr[10]={};
	srand(time(NULL));
	for(int i=0;i<10;i++)
	{
		switch(rand()%3)
		{
			case 0:
				arr[i]=new Retangle(rand()%10+1,rand()%10+1);
				break;
			case 1:
				arr[i]=new Circle(rand()%10+1);
				break;
			case 2:
				arr[i]=new Triggle(rand()%10+1,rand()%10+1,rand()%10+1);
				break;
		}
	}
	Shape& s=maxLen(arr);
	cout<<s.len()<<endl;
	return 0;
}
