#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

class Rectangle
{
private:
	int m_l;
	int m_w;
public:
	Rectangle(int l=0,int w=0):m_l(l),m_w(w){}

	friend bool compare(Rectangle,Rectangle);

	friend ostream& operator<<(ostream& os,Rectangle& re);
};

bool compare(Rectangle r1,Rectangle r2)
{
	return r1.m_l*r1.m_w < r2.m_l*r2.m_w;
}

ostream& operator<<(ostream& os,Rectangle& re)
{
	return os << re.m_l*re.m_w;
}

int main()
{
	srand(time(NULL));
	Rectangle re[10];
	for(int i=0; i<10; i++)
	{
		re[i] = Rectangle(rand()%10+1,rand()%10+1);
	}
	vector<Rectangle> v;
	for(int i=0; i<10; i++)
	{
		v.push_back(re[i]);
	}
	sort(v.begin(),v.end(),compare);
	vector<Rectangle>::iterator vs = v.begin();
	for(;vs!=v.end();vs++)
	{
		cout << *vs << endl;
	}
	return 0;
}

