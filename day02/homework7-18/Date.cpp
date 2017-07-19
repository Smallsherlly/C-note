#include <iostream>
using namespace std;

class Date
{
public:
	int year;
	int month;
	int day;
	Date(int y)
	{
		year = y;
	}
	Date(int y,int m)
	{
		year = y;
		month = m;
	}
	
	Date(int y,int m,int d)
	{
		year = y;
		month = m;
		day = d;
	}

};

int main()
{
	Date a(2017);
	Date b(2017,7);
	Date c(2017,7,18);

	cout << "year:" << a.year << endl;
	cout << "year:" << b.year << " month:" << b.month << endl;
	cout << "year:" << c.year << " month:" << c.month << " day:" << c.day << endl;
	return 0;	
}
