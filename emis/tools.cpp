#include "tools.h"

void anykey()
{
	cout << "按任意键返回。\n";
	cin.get();
}

int generator_id()
{
	static int id = 10000;
	ifstream fin("./data/id.dat");
	if(fin)
		fin >> id;
		
	fin.close();
	id++;
	ofstream fout("./data/id.dat");
	if(fout)
		fout << id;
	fout.close();
	return id;
}
