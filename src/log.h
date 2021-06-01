#pragma once
#include "minilogger.h"
#include<iostream>
#include<string>

using namespace std;

#define LOG(fmt, ...)	do{\
			char _buf[1024] = {0};\
			snprintf(_buf, sizeof(_buf), "[%s:%s:%d][LOG_NORMAL]" fmt"\n",__FILE__,__FUNCTION__,__LINE__, ##__VA_ARGS__);\
			mylog.Log(string(_buf));\
		}while(false)

extern Logger<TextDecorator> mylog;