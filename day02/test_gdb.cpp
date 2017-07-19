#include <iostream>
using namespace std;

void func(double b){}
void func(char a){}

int main()
{
	func(199);
	int i = 0;
	int sum = 0;
	for(; i<10; i++)
	{
		sum += i;
	}
	
	return 0;	
}
