#include <iostream>
using namespace std;

int main()
{
	int (*p)[4] = new int[4][4]{{10,11,12,13},{100,110,120,130},{1000,1100,1200,1300}};
	int i = 0,j = 0;
	for(i=0; i<4; i++)
	{
		for(j=0; j<3; j++)
		{
			p[3][i] += p[j][i];
		}
		cout << p[3][i] << endl;
	}
	
	return 0;	
}
