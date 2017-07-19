#include <iostream>
#include <cstring>

using namespace std;

class Message
{
	size_t m_len;//短信长度
	string m_str;//短信内容
public:
	Message(const string& str):m_str(str),m_len(m_str.length()){
		cout << m_len << endl;
		cout << m_str << endl;

	}

};

int main()
{
	string str("hello");
	cout << str.length() << endl;
	Message msg("world");
	return 0;	
}
