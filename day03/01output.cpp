#include <iostream>
using namespace std;

int main()
{
	int i = 0x12345678;
	char *p = reinterpret_cast<char*>(&i);
	int j = 0;
	for(; j<sizeof(i); j++)
	{
		cout << static_cast<int>(*(p+j))  << endl;
	}
	
	return 0;
}
