#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

class Employee
{
private:
	char* m_name;
	int m_id;
public:
	Employee(char* name=NULL,int id=0)
	{
		m_name = new char[strlen(name?name:"")+1];
		m_id = id;
	}
	friend istream& operator>>(istream& is,Employee& e);
	friend ostream& operator<<(ostream& os,Employee& e);
	
};

istream& operator>>(istream& is,Employee& e)
{
	return is >> e.m_name >> e.m_id;
}
ostream& operator<<(ostream& os,Employee& e)
{
	return os<< e.m_name  << e.m_id << endl;
}

int main()
{
	Employee e1;
	Employee e2;
	cin >> e1;
	cout << e1;
	fstream f("./data.txt",ios::out);
	if(f)
	{
		f << e1;
	}
	cout << e1 << endl;
	f.close();
	fstream f2("./data.txt",ios::in);
	if(f2)
	{
		f2 >> e2;
	}
	f2.close();
	cout << e2;

	
	return 0;	
}
