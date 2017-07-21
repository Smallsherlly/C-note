#include <iostream>
using namespace std;

class Point
{
private:
	int m_row;
	int m_col;
public:
	Point(int row=0,int col=0):m_row(row),m_col(col){}
	Point(const Point& that):m_row(that.m_row),m_col(that.m_col){}
	Point& operator=(const Point& that)
	{
		if(&that != this)
		{
			m_row = that.m_row;
			m_col = that.m_col;
		}
	}

	Point& operator+=(const Point& that)
	{
		m_row = m_row + that.m_row;
		m_col = m_col + that.m_col;
		return *this;
	}
	Point& operator-=(const Point& that)
	{
		m_row = m_row - that.m_row;
		m_col = m_col - that.m_col;
		return *this;
	}
	Point operator+(const Point& that)
	{
		return Point(m_row+that.m_row,m_col+that.m_col);
	}
	Point operator-(const Point& that)
	{
		return Point(m_row-that.m_row,m_col-that.m_col);
	}
	Point& operator<<(int num)
	{
		m_row = m_row -num;
		return *this;
	}
	Point& operator>>(int num)
	{
		m_row = m_row + num;
		return *this;
	}
	Point& operator!(void)
	{
		m_row = -m_row;
		return *this;
	}
	Point& operator~(void)
	{
		m_col = -m_col;
		return *this;
	}
	Point& operator-(void)
	{
		m_row = -m_row;
		m_col = -m_col;
		return *this;
	}
	void show()
	{
		cout << "(" << m_row << "," << m_col << ")" << endl;
	}
};

int main()
{
	Point p1(3,4);
	Point p2(5,6);
	(p2-p1).show();
	(p2 >> 3).show();
	return 0;	
}
