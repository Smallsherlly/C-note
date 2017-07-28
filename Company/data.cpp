#include <iostream>
#include <fstream>
using namespace std;

class Employee
{
private:
	string m_name;
	int m_id;
public:
	Employee(const string name="",int id=0)
	{
		m_name = name;
		m_id = id;
	}
	friend istream& operator>>(istream& is, Employee& e);
	friend ostream& operator<<(ostream& os,const Employee& e);
	
};

istream& operator>>(istream& is,Employee& e)
{
	return is >> e.m_name >> e.m_id;
}
ostream& operator<<(ostream& os,const Employee& e)
{
	return os<< e.m_name << "  " << e.m_id;
}

int main()
{
	Employee e1("lss",123);
	Employee e2("stt",333);
//	cin >> e1;
//	cout << e1;
	fstream f("./data.dat");
	if(f)
	{
		f << e1;
	}
//	cout << e1;
	f.close();
	fstream f2("./data.dat");
	if(f2)
	{
		
		f2 >> e1;
//	cout << e1;
	}
	f2.close();
	cout << e1;

	
	return 0;	
}
