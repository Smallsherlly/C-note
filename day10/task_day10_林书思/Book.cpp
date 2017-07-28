#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Book
{
private:
	string m_name;
	string m_author;
	double m_price;
public:
	Book(const string& name,const string& author,double price)
	{
		m_name = name;
		m_author = author;
		m_price = price;
	}
	friend bool compare(Book b1,Book b2);
	friend ostream& operator<<(ostream&,Book);
};

ostream& operator<<(ostream& os,Book b)
{
	return os << b.m_name << ":" << b.m_author << ":" << b.m_price << endl;
}
bool compare(Book b1,Book b2)
{
	if(b1.m_name == b2.m_name)
		return b1.m_author < b2.m_author;
	else
		return b1.m_name < b2.m_name;
}

int main()
{
	vector<Book> b;
	b.push_back(Book("格林童话","格林兄弟",33.0));
	b.push_back(Book("安徒生童话","安徒生",44.0));
	b.push_back(Book("格林童话","林书思",11));
	b.push_back(Book("纳尼亚战记","某人",11));
	b.push_back(Book("哥哥再爱我一次","小甜甜",11));
	b.push_back(Book("你这个猪头","大黄",11));
	b.push_back(Book("我不是猪头","大便",11));
	b.push_back(Book("红红火火","雪见",11));
	b.push_back(Book("陈稿大ZZ","妞妞",11));
	b.push_back(Book("TT丛林历险记","林书思",11));
	sort(b.begin(),b.end(),compare);
	vector<Book>::iterator vb = b.begin();
	for(;vb!=b.end();vb++)
	{
		cout << *vb;
	}
	
	return 0;	
}
