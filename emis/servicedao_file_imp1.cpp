#include "servicedao_file_imp1.h"
#include "tools.h"
#include <fstream>

void ServiceDaoFileImp1::load(vector<Department>& de)
{
	int num = 0;
	int index = 0;
	ifstream f("./data/id.dat");

	ifstream fin("./data/services.dat");
	Department pe;
	Employee ep;
	vector<Department>::iterator it = de.begin();
	for(; fin >> pe;)
	{
		de.push_back(pe);
		vector<Employee>& emp = de.at(index).getEmployee();
		for(int j=0; j<de.at(index).getEN();j++)
		{
			fin >> ep;
			emp.push_back(ep);  
		}
		index++;
	}
	fin.close();

}

void ServiceDaoFileImp1::save(vector<Department>& de)
{
	ofstream fout("./data/services.dat");
	vector<Department>::iterator it = de.begin();
	for(;it!=de.end();it++)
	{
		fout << *it;
		vector<Employee> emp = (*it).getEmployee();
		vector<Employee>::iterator pt = emp.begin();
		for(;pt!=emp.end();pt++)
		{
			fout << *pt;
		}
	}
	fout.close();
	
}



