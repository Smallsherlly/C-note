#include <iostream>
using namespace std;

class Eye
{
public:
	Eye()
	{
		cout << "I am Eye\n" ;
	}
	
};
class Ear
{
public:
	Ear()
	{
		cout << "I am Ear\n" ;
	}
	
};

class Head
{
public:
	Eye m_eye;
	Ear m_ear;
public:
	Head()
	{
		cout << "I am head\n";	
	}
};


int main()
{
	Head h;
	h();
	Head();
//	h.m_eye = Eye();
	return 0;	
}
