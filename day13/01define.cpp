#include <iostream>
using namespace std;

#define max(x,y) ((x)>(y)?(x):(y))

int main()
{
	cout << max(1,3)<<endl;
	cout << max(3.14,5.68) << endl;
	cout << max(string("hello"),string("world")) << endl;
	cout << max('a','z') << endl;
	return 0;
}
