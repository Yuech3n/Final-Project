/*************************************************************************
【文件名】                  DateTime.cpp
【功能模块和目的】          创建一个日期时间的对象
【开发者及日期】            王雨晨 2021.8
*************************************************************************/

#include"DateTime.h"
#include"Date.h"
#include"Time.hpp"
#include<string>
using namespace std;


/*************************************************************************
【函数名称】        DateTime
【函数功能】        给定参数（可缺省）创建一个时间日期对象
【参数】            年月日 时分秒
【返回值】          无
【开发者及日期】    王雨晨 2021.8
*************************************************************************/
DateTime::DateTime(unsigned Y, unsigned Mon, unsigned D,
	unsigned H, unsigned Min, unsigned S){
	this->DatePart.Set(Y, Mon, D);
	this->TimePart.Set(H, Min, S);
}

//拷贝构造函数
DateTime::DateTime(const DateTime& p) {
	this->DatePart = p.DatePart;
	this->TimePart = p.TimePart;
}

//赋值号运算符
DateTime DateTime::operator=(const DateTime& p) {
	if (this != &p) {
		this->DatePart = p.DatePart;
		this->TimePart = p.TimePart;
	}
	return *this;
}

/*************************************************************************
【函数名称】        ConvertToStr
【函数功能】        将对象转化为标准字符串
【参数】            DateTime对象
【返回值】          string类型的时间字符串（如20210805204000）
【开发者及日期】    王雨晨 2021.8
*************************************************************************/
string DateTime::ConvertToStr(const DateTime& p) {
	//先建立字符串形式的副本
	string YearStr = to_string(p.DatePart.Year);
	string MonthStr = to_string(p.DatePart.Month);
	string DayStr = to_string(p.DatePart.Day);
	string HourStr = to_string(p.TimePart.Hour);
	string MinuteStr = to_string(p.TimePart.Minute);
	string SecondStr = to_string(p.TimePart.Second);
	//格式统一
	if (YearStr.length()<4) {
		YearStr.insert(0,string("0"));
	}
	if (MonthStr.length()<2) {
		MonthStr.insert(0, string("0"));
	}
	if (DayStr.length() < 2) {
		DayStr.insert(0, string("0"));
	}
	if (HourStr.length() < 2) {
		HourStr.insert(0, string("0"));
	}
	if (MinuteStr.length() < 2) {
		MinuteStr.insert(0, string("0"));
	}
	if (SecondStr.length() < 2) {
		SecondStr.insert(0, string("0"));
	}
	//合并
	string DateTimeStr{};
	DateTimeStr += YearStr += MonthStr += DayStr += HourStr += MinuteStr += SecondStr;
	return DateTimeStr;
}

/*************************************************************************
【函数名称】        ConvertToTime
【函数功能】        将标准字符串转化为对象
【参数】            string类型的时间字符串
【返回值】          DateTime对象
【开发者及日期】    王雨晨 2021.8
*************************************************************************/
//把标准字符串转化为时间
DateTime DateTime::ConvertToTime(const string& p) {
	if (p.size() != 14) {
		throw string("Invalidable time input");
	}
	unsigned Year;
	unsigned Month;
	unsigned Day;
	unsigned Hour;
	unsigned Minute;
	unsigned Second;
	string temp;

	temp = p.substr(0, 4);
	Year = (unsigned)stoul(temp);

	temp = p.substr(4, 2);
	Month = (unsigned)stoul(temp);

	temp = p.substr(6, 2);
	Day = (unsigned)stoul(temp);

	temp = p.substr(8, 2);
	Hour = (unsigned)stoul(temp);

	temp = p.substr(10, 2);
	Minute = (unsigned)stoul(temp);

	temp = p.substr(12, 2);
	Second = (unsigned)stoul(temp);
	DateTime a(Year, Month, Day, Hour, Minute, Second);
	return a;
}

//关系判断
bool DateTime::operator>(const DateTime& p) const {
	return DateTime::ConvertToStr(*this) > DateTime::ConvertToStr(p);
}
bool DateTime::operator<(const DateTime& p) const {
	return DateTime::ConvertToStr(*this) < DateTime::ConvertToStr(p);
}
bool DateTime::operator==(const DateTime& p) const {
	return DateTime::ConvertToStr(*this) == DateTime::ConvertToStr(p);
}

/*************************************************************************
【函数名称】        Set
【函数功能】        设置当前日期时间对象的值
【参数】            年月日时分秒
【返回值】          无
【开发者及日期】    王雨晨 2021.8
*************************************************************************/
void DateTime::Set(unsigned Y, unsigned Mon, unsigned D,
	unsigned H, unsigned Min, unsigned S) {
	this->DatePart.Set(Y, Mon, D);
	this->TimePart.Set(H, Min, S);
}