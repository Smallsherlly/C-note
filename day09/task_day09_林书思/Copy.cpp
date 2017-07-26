#include <iostream>
#include <fstream>
using namespace std;

void Copy(char* str1,char* str2)
{
	fstream f1(str1,ios::in|ios::ate);
	fstream f2(str2,ios::out);
	try
	{
		if(!f1||!f2)
			throw string("读写文件失败");;
	}catch(string& e)
	{
		cout << e << endl;
	}
	int temp = f1.tellg();
	char p[1024] = {};
	f1.seekg(0,ios::beg);
	f1.read(p,temp);
	cout << p;
	f2.write(p,temp);
	f1.close();
	f2.close();


}

int main()
{
	char str1[50];
	char str2[50];
	cout << "请输入源文件路径" << endl;
	cin >> str1;
	cout << "请输入目标文件路径" << endl;
	cin >> str2;
	Copy(str1,str2);
	return 0;
}
