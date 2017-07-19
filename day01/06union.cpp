#include <iostream>
using namespace std;

int main()
{
	//匿名联合
	union 
	{
		int n;
		char crr[4];
	};
	n = 0x12345678;
	cout << hex << (int)crr[0] << endl;
	cout << hex << (int)crr[1] << endl;
	cout << hex << (int)crr[2] << endl;
	cout << hex << (int)crr[3] << endl;
	return 0;
}
