#include <iostream>
using namespace std;

class Circle
{
private:
	double m_r;
	static double m_pi;//所有的对象的m_pi是相等的

public:
	Circle(double r)
	{
		this->m_r = r;
	}
	double area()
	{
		return m_pi * this->m_r * this->m_r;
	}
	double len()
	{
		return m_pi * this->m_r * 2;
	}

};

double Circle::m_pi = 3.1415926;

int main()
{
	Circle c(10);
	cout << c.area() << endl;
	cout << c.len() << endl;
	cout << Circle::m_pi << endl;
	return 0;	
}
