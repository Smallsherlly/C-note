#include <iostream>
#include <stdexcept>
#include <cstdio>
using namespace std;


class FileError:public exception
{
private:
	string err;
public:
	FileError(const char* str="文件错误"):err(str){}
	const char* what()throw (const char*)
	{
		return err.c_str();
	}
	~FileError()throw(){}

};

class OpenFileError:public FileError
{
public:
	OpenFileError(const char* str="打开文件失败"):FileError(str){}
/*	const char* what()throw(const char*)
	{
		return err.c_str();
	}
	~OpenFileError()throw(){}*/

};
class MemoryError:public exception
{
private:
	string err;
public:
	MemoryError(const char* str="内存错误"):err(str){}
	const char* what()throw(const char*)
	{
		return err.c_str();
	}
	~MemoryError()throw(){}
};
void func()
{
	FILE* fp = fopen("./a.txt","r");
	if(fp == NULL)
	{
		throw OpenFileError();
	}
	try
	{
		int* p = new int[0xfffffffe];
		if(p = NULL)
			throw MemoryError("分配内存失败");
	}catch(bad_alloc& e)
	{
		throw MemoryError("分配内存失败");
	}
}

int main()
{
	try
	{
		func();
	}catch(OpenFileError& e)
	{
		cout << e.what() << endl;
	}catch(MemoryError& e)
	{
		cout << e.what() << endl;

	}catch(FileError& e)
	{
		cout << e.what() << endl;
	}
	return 0;	
}
