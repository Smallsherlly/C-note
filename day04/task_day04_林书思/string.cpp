#include<iostream>
#include<cstring>
using namespace std;

class IntPoint{
private:
	int *m_p;
public:
	IntPoint(const int& num){
		m_p = new int(num);	
	}
	IntPoint(const IntPoint& that){
		m_p = new int(*(that.m_p));
	}
	~IntPoint(void){
		if(m_p != NULL){
			delete m_p;	
		}
		m_p = NULL;
	}
	IntPoint& operator=(const IntPoint& that){
		//if(that == *this)
		if(&that != this){
			*m_p = *that.m_p;
		}	
		return *this;
	}
};

#include <cstring>

class String{
private:
	char *m_data;
public:
	String(const char * str):
		m_data(strcpy(new char[strlen(str?str:"")+1],str?str:""))
	{
		//指针得判断是否为空
	/*	m_data = new char[strlen(str?str:"")+1];
		strcpy(m_data,str?str:"");
	*/
	/*
		if(str == NULL){
			m_data = new char[1];//不能char('\0')
			*m_data = '\0';
		}else{
			size_t len = strlen(str)+1;
			m_data = new char[len];
			strcpy(m_data,str);
		}
	*/
	}
	~String(void){
		if(m_data != NULL){
			delete [] m_data;	
		}
		m_data = NULL;
	}
	String(const String& that):
	   m_data(strcpy(new char[strlen(that.m_data)+1],that.m_data))
	{
		//m_data = new char[strlen(that.m_data)+1];
		//strcpy(m_data, that.m_data);
	}
	
	String& operator=(const String& that){
		if(&that != NULL){
			/*菜鸟
			delete [] m_data;
			m_data=new char[strlen(that.m_data)+1];
			strcpy(m_data,that.m_data);
			*/
			//万一第70行出错了，原来的数据也delete
			//得先分配内存
			//再释放空间
			//拷贝数据
			/*高手
			char* p_data = new char[strlen(that.m_data)+1];
			delete [] m_data;
			m_data = strcpy(p_data,that.m_data);
			*/
			String str(that);//拷贝构造
			swap(m_data,str.m_data);
		}
		return *this;
	}
	const char * c_str(){
		return m_data;	
	}
	String& append(const char* str)
	{
		if(str!=NULL)
		{
		/*	int i = 0;        caiji
			int j = 0;
			int len = strlen(m_data);
			char* cp = new char[len+1];
			strcpy(cp,m_data);
			delete[] m_data;
			m_data = new char[len+strlen(str)+1];
			strcpy(m_data,cp);
			while(*(m_data+i)!='\0')
			i++;
			while(*(str+j)!='\0')
			{
				*(m_data+i+j) = *(str+j);
				j++;
			}
			*(m_data+i+j) = '\0';
			*/
			char* p_data = new char[strlen(m_data)+strlen(str)+1];
			strcpy(p_data,m_data);
			delete[] m_data;
			m_data = strcat(p_data,str);
		}
		return *this;
	}

	char& at(size_t index)
	{
		size_t len = strlen(m_data);
		if(index > len-1)
		{
			cout << "out of range" << endl;
		}
		else
		{
			return *(m_data+index);
		}

	}
	
	int compare(const char *str)
	{
		int i = 0;
		while(*(m_data+i)!='\0'&&*(str+i)!='\0')
		{
			if(*(m_data+i) > *(str+i))
			{
				return 1;
			}
			else if(*(m_data+i) < *(str+i))
			{
				return -1;
			}
			i++;
		}
		return 0;
	}

	bool empty()
	{
		return m_data?0:1;
	}

	size_t size()
	{
		size_t iNum = 0;
		while(*(m_data+iNum)!='\0')
			iNum++;

		return iNum;
	}
	size_t length()
	{
		size_t iNum = 0;
		while(*(m_data+iNum)!='\0')
			iNum++;

		return iNum;
	}

	String& erase(size_t index = 0,size_t num = 0)
	{
		int len = strlen(m_data)+1-num;
		char* p_data = new char[len];
		int i = 0;
		int j = 0;
		for(i=0; i<index; i++)
		{
			*(p_data+i) = *(m_data+i);
		}
		for(j=index+num; j<strlen(m_data)+1; j++,i++)
		{
			*(p_data+i-1) = *(m_data+j);
		}
		delete[] m_data;
		m_data = new char[len];
		strcpy(m_data,p_data);
		return *this;
	}
	
	String& insert(size_t index,const char* str)
	{
		int len = strlen(m_data)+strlen(str)+1;
		char* p_data = new char[len];
		int i = 0;
		int j = 0;
		for(i=0; i<index; i++)
		{
			*(p_data+i) = *(m_data+i);
		}
		for(j=0; i<index+strlen(str); i++,j++)
		{
			*(p_data+i) = *(str+j);
		}
		j = i ;
		for(i=index; i<strlen(m_data)+1; i++,j++)
		{
			*(p_data+j) = *(m_data+i);
		}
		delete[] m_data;
		m_data = new char[len];
		strcpy(m_data,p_data);
		return *this;
	}
};

int main(){
	String str1("ABCDEF");
	String str2("ABFD");
/*	String str2(str1);
	String str3(NULL);
	str3 = str1;
	String str4("美国佬");
	//str3 = str4;
	str3.operator=(str4);
	cout << str1.c_str() << endl;
	cout << str2.c_str() << endl;
	cout << str3.c_str() << endl;
	cout << str4.c_str() << endl;
*/
	char arr[10] = "ABFD";
	char brr[10] = "xxxx";
	str1.append(arr);
	char c = str1.at(3);
	cout << str1.c_str() << endl;
	cout << c << endl;
	cout << str1.compare(arr) << endl;
	cout << str1.size() << endl;
	cout << str1.erase(3,2).c_str() << endl;
	cout << str1.insert(3,brr).c_str() << endl;
	return 0;	
}



