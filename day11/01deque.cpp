#include <iostream>
#include <deque>

using namespace std;

template<typename IT>
void print(IT begin,IT end)
{
	while(begin != end)
		cout<< *begin++ << " ";
	cout << endl;
}

int main()
{
	deque<int> dq;
	dq.push_back(1);
	dq.push_front(2);
	dq.push_back(3);
	dq.push_front(4);
	dq.push_back(5);
	print(dq.begin(),dq.end());
	return 0;	
}
