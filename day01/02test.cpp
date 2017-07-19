#include <iostream>
#include <cstring>
using namespace std;

int func(int a,int b)
{
	return a>b?a:b;
}

char func(char a,char b)
{
	return a>b?a:b;
}

double func(double a,double b)
{
	return a>b?a:b;
}

char* func(char* a,char* b)
{
	return strcmp(a,b)>0?a:b;
}

int main()
{
	char a[10] = "abc";
	char b[10] = "fgh";
	cout << func(a,b) << endl;
	return 0;	
}
