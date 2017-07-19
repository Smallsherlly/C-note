#include <iostream>
using namespace std;

struct Int
{
	int i;
	Int& up()
	{
		++i;
		return *this;
	}
};

int main()
{
	Int n = {1};
	n.up().up().up();
	cout << n.i << endl;

	return 0;
}
