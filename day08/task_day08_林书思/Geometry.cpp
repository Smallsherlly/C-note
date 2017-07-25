#include <iostream>
#include <cstdlib>
#include <ctime>
#define PI 3.1415
using namespace std;

class Shape
{
public:
	Shape(){}
	virtual double area(){}
	virtual double volume(){}
	friend int areaMax(Shape*,int);
};

//立方体
class Cube:public Shape
{
private:
	int m_l;
	int m_w;
	int m_h;
public:
	Cube(int l,int w,int h):m_l(l),m_w(w),m_h(h){}
	Cube(const Cube& that)
	{
		m_l = that.m_l;
		m_w = that.m_w;
		m_h = that.m_h;
	}
	double area()
	{
		return (m_l*m_w+m_l*m_h+m_l*m_h)*2;
	}
	double volume()
	{
		return m_l*m_w*m_h;
	}

};

//长方体
class Cuboid:public Shape
{
private:
	int m_l;
	int m_w;
	int m_h;
public:
	Cuboid(int l,int w,int h):m_l(l),m_w(w),m_h(h){}
	double area()
	{
		return (m_l*m_w+m_l*m_h+m_l*m_h)*2;
	}
	double volume()
	{
		return m_l*m_w*m_h;
	}

};

//球体
class Sphere:public Shape
{
private:
	int m_r;

public:
	Sphere(int r):m_r(r){}
	double area()
	{
		return 4*PI*m_r*m_r;
	}
	double volume()
	{
		return 4/3*PI*m_r*m_r*m_r;
	}
};

//圆柱体
class Cylinders:public Shape
{
private:
	int m_r;
	int m_h;
public:
	Cylinders(int r,int h):m_r(r),m_h(h){}
	double area()
	{
		return 2*PI*m_r*(m_h+m_r);
	}
	double volume()
	{
		return PI*m_r*m_r*m_h;
	}
};

int areaMax(Shape** s,int len)
{
	Shape** sp = s;
	int i = 0;
	double Max = 0;
	int flag = 0;
	for(i=0; i<len; i++)
	{
		if(sp[i]->area()>Max)
		{
			Max = sp[i]->area();
			flag = i;
		}
	}
	cout << Max << endl;

}

int volumeMax(Shape** s,int len)
{
	Shape** sp = s;
	int i = 0;
	double Max = 0;
	int flag = 0;
	for(i=0; i<len; i++)
	{
		if(sp[i]->volume()>Max)
		{
			Max = sp[i]->volume();
			flag = i;
		}
	}
	cout << Max << endl;

}



int main()
{
	int i = 0;
	Shape* arr[10] = {};
	srand(time(NULL));
	for(i=0; i<10; i++)
	{
		switch(rand()%4)
		{
			case 0:
				arr[i] = new Cube(rand()%10+1,rand()%10+1,rand()%10+1);
				break;
			case 1:
				arr[i] = new Cuboid(rand()%10+1,rand()%10+1,rand()%10+1);
				break;
			case 2:
				arr[i] = new Cylinders(rand()%10+1,rand()%10+1);
				break;
			case 3:
				arr[i] = new Sphere(rand()%10+1);
				break;
		}
	}
	areaMax(arr,10);
	volumeMax(arr,10);
	return 0;
}
