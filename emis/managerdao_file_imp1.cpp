#include "managerdao_file_imp1.h"
#include <fstream>
ManagerDaoFileImp1::ManagerDaoFileImp1(){}
ManagerDaoFileImp1::~ManagerDaoFileImp1(){}
void ManagerDaoFileImp1::save(vector<Manager>& managers)
{
	ofstream fout("./data/manager.dat");
	for(int i=0; i<managers.size(); i++)
	{
		fout.write((const char*)&managers.at(i),sizeof(Manager));
	}
}
void ManagerDaoFileImp1::load(vector<Manager>& managers)
{
	ifstream fin("./data/manager.dat");
	Manager ws;
	while(fin.read((char*)&ws,sizeof(Manager)))
	managers.push_back(ws);

}



