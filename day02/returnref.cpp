#include <iostream>
using namespace std;

int g_num = 100;

int &func1()
{
	return g_num;
}

int& func2()
{
	int num = 1000;
	return num;
}

int main()
{
	int t = func1();
	cout << t << endl;
	int& r = func1();
	return 0;	
}
