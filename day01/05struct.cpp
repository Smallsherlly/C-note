#include <iostream>
using namespace std;

struct A
{
	int a;
	void show(){
	}
};

struct B
{

};

int main()
{
	A a;
	cout << sizeof(B) << endl;	
	return 0;
}
