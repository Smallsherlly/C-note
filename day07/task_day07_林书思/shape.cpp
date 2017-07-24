#include <iostream>
#define PI 3.14159
using namespace std;

class Point 
{
private:
	int m_x;
	int m_y;
public:
	Point(int x=0,int y=0):m_x(x),m_y(y){}
	Point(const Point& that):m_x(that.m_x),m_y(that.m_y){}
	friend class Rectangle;
	friend class Circle;
};

class Shape
{
private:
	Point m_cp;
public:
	Shape(Point p):m_cp(p){}
	const Point& getPoint()
	{
		return m_cp;
	}
};

class Rectangle:public Shape
{
private:
	int m_height;
	int m_weight;
public:
	Rectangle(int h,int w,Point p):m_height(h),m_weight(w),Shape(p){}
	int area()
	{
		return m_height*m_weight;
	}

	int length()
	{
		return 2*(m_height+m_weight);
	}

	bool isBelong(Point p)
	{
		const Point& ip = getPoint();
		if(p.m_x - ip.m_x > m_weight/2||p.m_x - ip.m_x
			< -m_weight/2||p.m_y - ip.m_y > m_height/2||
			p.m_y - ip.m_y < -m_height/2)
			return false;
		else
			return true;
	}

};

class Circle:public Shape
{
private:
	int m_r;
public:
	Circle(int r,Point p):m_r(r),Shape(p){}
	int area()
	{
		return PI*m_r*m_r; 
	}

	int length()
	{
		return 2*PI*m_r;
	}

	bool isBelong(Point p)
	{
		const Point& ip = getPoint();
		int s = (p.m_x-ip.m_x)*(p.m_x-ip.m_x)+(p.m_y-ip.m_y)*(p.m_y-ip.m_y);
		if(s > m_r*m_r)
			return false;
		else
			return true;
	}
};

int main()
{
	Point p1(2,2);
	Point p2(7,7);
	Rectangle re(4,4,p1);
	cout << re.area() << endl;
	cout << re.length() << endl;
	cout << boolalpha << re.isBelong(p2) << endl;
	Circle ci(5,p1);
	cout << boolalpha << ci.isBelong(p2) << endl;
	
	return 0;	
}
