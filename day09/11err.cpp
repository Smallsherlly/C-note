#include <iostream>
using namespace std;

void func1()throw(int,char,double)
{
	throw string("error");
}

void func2()
{

}

void func4()throw(int)
{
	
}
	
int main()
{
	func1();
	return 0;	
}
