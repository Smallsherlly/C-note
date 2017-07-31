#ifndef _LOG_H__
#define _LOG_H__

#include <iostrem>
using namespace std;

#if LOG_LEVEL>=4

#define LOG_ERROR(fmt,args...) printf("[error]%s line:%d func():%s "fmt,__FILE__,__LINE__,__func__ ,##args);
#define LOG_INFO(fmt,args...)
#define LOG_TRACE(fmt,args...)
#define LOG_DEBUG(fmt,args...)

#elif LOG_LEVEL>=3
#define LOG_ERROR(fmt,args...) printf("[error]%s line:%d func():%s  "fmt,__FILE__,__LINE__,__func__,##args);
#define LOG_INFO(fmt,args...) printf("[error]%s line:%d func():%s "fmt,__FILE__,__LINE__,__func__,##args);
#define LOG_TRACE(fmt,args...)
#define LOG_DEBUG(fmt,args...)

#elif LOG_LEVEL>=2
#define LOG_ERROR(fmt,args...) printf("[error]%s line:%d func():%s "fmt,__FILE__,__LINE__,__func__,##args);
#define LOG_INFO(fmt,args...) printf("[error]%s line:%d func():%s "fmt,__FILE__,__LINE__,__func__,##args);
#define LOG_TRACE(fmt,args...) printf("[error]%s line:%d func():%s "fmt,__FILE__,__LINE__,__func__,##args);
#define LOG_DEBUG(fmt,args...)

#elif LOG_LEVEL>=1
#define LOG_ERROR(fmt,args...) printf("[error]%s line:%d func():%s "fmt,__FILE__,__LINE__,__func__,##args);
#define LOG_INFO(fmt,args...) printf("[error]%s line:%d func():%s "fmt,__FILE__,__LINE__,__func__,##args);
#define LOG_TRACE(fmt,args...) printf("[error]%s line:%d func():%s "fmt,__FILE__,__LINE__.__func__,##args);
#define LOG_DEBUG(fmt,args...) printf("[error]%s line:%d func():%s "fmt,__FILE__,__LINE__,__func__,##args);

#endif

