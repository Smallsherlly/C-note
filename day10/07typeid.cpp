#include <iostream>
#include <typeinfo>
using namespace std;

int main()
{
	cout << typeid(int).name() << endl;
	return 0;	
}
