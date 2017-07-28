#ifndef _TOOLS_H__
#define _TOOLS_H__
#include <cstdlib>
#include <iostream>
#include <fstream>
using namespace std;

void anykey()
{
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

#endif //_TOOLS_H__
