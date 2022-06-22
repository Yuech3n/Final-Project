/*************************************************************************
【文件名】                  DateTime.h
【功能模块和目的】          创建一个日期时间的对象
【开发者及日期】            王雨晨 2021.8
*************************************************************************/
#ifndef _DATETIME_H_
#define _DATETIME_H_
#include"Date.h"
#include"Time.hpp"
#include<string>
using namespace std;
/*************************************************************************
【类名】             DateTime
【功能】             创建一个含有日期部分与时间部分的DateTime对象
【接口说明】         DateTime(unsigned Y = 1900,unsigned Mon = 1, unsigned D = 1,
						unsigned H = 0 , unsigned Min = 0, unsigned S = 0); 可缺省的构造函数，生成一个给定的时间日期
					 ConvertToStr(const DateTime& p) 把给定时间日期转化为标准字符串形式
					 ConvertToTime(const string& p)  把标准字符串形式的时间日期转化为DateTime类型的对象
【开发者及日期】     王雨晨 2021.8
*************************************************************************/
class DateTime{
public:
	//给定参数（可缺省），创建一个时间日期对象
	DateTime(unsigned Y = 1900,unsigned Mon = 1, unsigned D = 1,
		unsigned H = 0 , unsigned Min = 0, unsigned S = 0);
	//拷贝构造函数
	DateTime(const DateTime& p);
	//赋值号运算符
	DateTime operator=(const DateTime& p);
	//将datetime对象转化为标准字符串形式时间
	static string ConvertToStr(const DateTime& p);
	//将标准字符串形式时间转化为对象
	static DateTime ConvertToTime(const string& p);
	//运算符重载 > < ==
	bool operator>(const DateTime& p) const;
	bool operator<(const DateTime& p) const ;
	bool operator==(const DateTime& p) const;
	//设置当前对象的值
	void Set(unsigned Y, unsigned Mon, unsigned D,
		unsigned H, unsigned Min, unsigned S);
	//有一个public的Date成员和一个Time成员，封装部分已经由其类完成，设为public有利于使用内部功能
	//以及读取数据
	Date DatePart;
	Time TimePart;
};
#endif
