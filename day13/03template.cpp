#include <iostream>
using namespace std;

template<typename T>
T max(const int& x,const int& y)
{
	return x>y?x:y;
}

template<typename X,typename K>
K maxArray(X arr[],K len)
{
	K max = arr[0];
	for(int i=0; i<len; i++)
	{
		if(arr[i]>max)
			max = arr[i];
	}
	return max;
}

int main()
{
	int arr[4] = {3,5,6,7};
	cout << maxArray(arr,4) << endl;
	return 0;
}
