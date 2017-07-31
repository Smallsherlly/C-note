#include <iostream>
#include <cstdio>
using namespace std;

#if LOG_LEVEL>=4

#define LOG_ERROR(fmt,args...) printf("[error]%s line:%d "fmt,__FILE__,__LINE__,##args);
#define LOG_INFO(fmt,args...)
#define LOG_TRACE(fmt,args...)
#define LOG_DEBUG(fmt,args...)

#elif LOG_LEVEL>=3
#define LOG_ERROR(fmt,args...) printf("[error]%s line:%d "fmt,__FILE__,__LINE__,##args);
#define LOG_INFO(fmt,args...) printf("[error]%s line:%d "fmt,__FILE__,__LINE__,##args);
#define LOG_TRACE(fmt,args...)
#define LOG_DEBUG(fmt,args...)

#elif LOG_LEVEL>=2
#define LOG_ERROR(fmt,args...) printf("[error]%s line:%d "fmt,__FILE__,__LINE__,##args);
#define LOG_INFO(fmt,args...) printf("[error]%s line:%d "fmt,__FILE__,__LINE__,##args);
#define LOG_TRACE(fmt,args...) printf("[error]%s line:%d "fmt,__FILE__,__LINE__,##args);
#define LOG_DEBUG(fmt,args...)

#elif LOG_LEVEL>=1
#define LOG_ERROR(fmt,args...) printf("[error]%s line:%d "fmt,__FILE__,__LINE__,##args);
#define LOG_INFO(fmt,args...) printf("[error]%s line:%d "fmt,__FILE__,__LINE__,##args);
#define LOG_TRACE(fmt,args...) printf("[error]%s line:%d "fmt,__FILE__,__LINE__,##args);
#define LOG_DEBUG(fmt,args...) printf("[error]%s line:%d "fmt,__FILE__,__LINE__,##args);

#endif
int main()
{
//	printf("%s %s %d\n",__FILE__,__LINE__);
	
	LOG_INFO("main() begin\n");

	int ip = 100;//表示这个信息非常重要，关系到程序运行
	
	//或者分支选择时一个控制代码走向的开关
	LOG_ERROR("%d\n",ip);
	
	LOG_TRACE("%d\n",ip);

	char buf[24] = "socket";
	LOG_TRACE("%s\n",buf);

	LOG_INFO("main() end\n");
	return 0;
}
