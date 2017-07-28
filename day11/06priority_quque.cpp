#include <iostream>
#include <queue>
#include <vector>
#include <list>
using namespace std;

template<typename IT>
void print(IT begin,IT end)
{
	while(begin!=end)
		cout << *begin++ << " ";
	cout << endl;
}

class A
{
public:
	bool operator<(const A& a)const
	{
		return true;
	}
};

int main()
{
	priority_queue<int,vector<int>> pq;
	pq.push(9);
	pq.push(8);
	pq.push(7);
	pq.push(6);
	for(int i=0; i<pq.size();)
	{
		cout << pq.top() << " ";
		pq.pop();
	}
	cout << endl;
	priority_queue<A> p;
	A a;
	p.push(a);
	return 0;	
}
