/*************************************************************************
【文件名】                 Date.cpp
【功能模块和目的】         创建，编辑一个日期（年月日）
【开发者及日期】           王雨晨 2021.7
*************************************************************************/
#include<iostream>
#include<string>
#include"Date.h"
using namespace std;
//默认年份范围
unsigned Date::m_MinYear = 1900;
unsigned Date::m_MaxYear = 9999;
//默认初始化年月日
unsigned Date::m_DefaultYear = 1900;
unsigned Date::m_DefaultMonth = 1;
unsigned Date::m_DefaultDay = 1;

/*************************************************************************
【函数名称】       EditYearRange
【函数功能】       修改合理的年份范围
【参数】           合理年份的最小与最大值
【返回值】         无
【开发者及日期】   王雨晨 2021.7
*************************************************************************/
void Date::EditYearRange(unsigned Min, unsigned Max) {
	if (Max> Min) {
		Date::m_MaxYear = Max;
		Date::m_MinYear = Min;	
		return;
	}
	else {
		throw string("YearRange error");
	}
}

/*************************************************************************
【函数名称】       EditDefaultDate
【函数功能】       修改默认构造的日期
【参数】           默认的年月日
【返回值】         无
【开发者及日期】   王雨晨 2021.7
*************************************************************************/
void Date::EditDefaultDate(unsigned Year, unsigned Month, unsigned Day) {
	if (Date::IsValidDate(Year, Month, Day)) {
		Date::m_DefaultYear = Year;
		Date::m_DefaultMonth = Month;
		Date::m_DefaultDay = Day;
		return;
	}
	else {
		throw string("Date set error");
	}
}

/*************************************************************************
【函数名称】       Set
【函数功能】       编辑更改当前对象的时间
【参数】           要更改的年月日
【返回值】         无
【开发者及日期】   王雨晨 2021.7
*************************************************************************/
void Date::Set(unsigned Year, unsigned Month, unsigned Day) {
	if(IsValidDate(Year,Month,Day)){
		this->m_Year = Year;
		this->m_Month = Month;
		this->m_Day = Day;
		return;
	}
	else {
		throw string("Date set error");
	}
}

//构造函数
Date::Date(unsigned Year, unsigned Month, unsigned Day) : Year(m_Year), Month(m_Month), Day(m_Day),
	MinYear(m_MinYear), MaxYear(m_MaxYear),DefaultYear(m_DefaultYear), DefaultMonth(m_DefaultMonth), DefaultDay(m_DefaultDay) {
	Set(Year, Month, Day);
}
//拷贝构造函数
Date::Date(const Date& p) : Year(m_Year), Month(m_Month), Day(m_Day),
MinYear(m_MinYear), MaxYear(m_MaxYear), DefaultYear(m_DefaultYear), DefaultMonth(m_DefaultMonth), DefaultDay(m_DefaultDay) {
	this->m_Year  = p.m_Year;
	this->m_Month = p.m_Month;
	this->m_Day   = p.m_Day;
}
//赋值号运算符重载
Date Date::operator=(const Date& p) {
	if(this != &p){
		this->m_Year = p.m_Year;
		this->m_Month = p.m_Month;
		this->m_Day = p.m_Day;
	}
	return *this;
}

/*************************************************************************
【函数名称】       IsValidDate
【函数功能】       判断给定日期是否合理
【参数】           年月日
【返回值】         bool 是否合理
【开发者及日期】   王雨晨 2021.7
*************************************************************************/
bool Date::IsValidDate(unsigned Year, unsigned Month, unsigned Day) {
	//先判断是否是闰年
	
	//第一层判断年月日是否负责基本条件
	if (Year >= m_MinYear && Year <= m_MaxYear
		&& Month > 0 && Month < 13 && Day >0) {
		//判断除二月外每个月份的日期是否合理
		if (((Month == 1 || Month == 3 || Month == 5 || Month == 7 || Month == 8 || Month == 10 || Month == 12) && Day <= 31)
			|| ((Month == 4 || Month == 6 || Month == 9 || Month == 11) && Day <= 30)) {
			return true;
		}
		//判断二月
		else if (Month == 2 && Day <= 29) {
			if (Date::IsLeapYear(Year) || Day <= 28) {
				return true;
			}
			else {
				return false;
			}
		}
		else {
			return false;
		}
	}
	else {
		return false;
	}
}

/*************************************************************************
【函数名称】       IsValidDate
【函数功能】       判断当前对象日期是否合理
【参数】           无
【返回值】         bool 是否合理
【开发者及日期】   王雨晨 2021.7
*************************************************************************/
bool Date::IsValidDate() {
	//先判断是否是闰年

//第一层判断年月日是否负责基本条件
	if (Year >= m_MinYear && Year <= m_MaxYear
		&& Month > 0 && Month < 13 && Day >0) {
		//判断除二月外每个月份的日期是否合理
		if (((Month == 1 || Month == 3 || Month == 5 || Month == 7 || Month == 8 || Month == 10 || Month == 12) && Day <= 31)
			|| ((Month == 4 || Month == 6 || Month == 9 || Month == 11) && Day <= 30)) {
			return true;
		}
		//判断二月
		else if (Month == 2 && Day <= 29) {
			if (Date::IsLeapYear(Year) || Day <= 28) {
				return true;
			}
			else {
				return false;
			}
		}
		else {
			return false;
		}
	}
	else {
		return false;
	}
}

/*************************************************************************
【函数名称】       IsLeapYear
【函数功能】       判断当给定年份是否是闰年
【参数】           无
【返回值】         bool 是否是闰年
【开发者及日期】   王雨晨 2021.7
*************************************************************************/
bool Date::IsLeapYear(unsigned Year) {
	return ((Year % 400 == 0) || (Year % 100 != 0 && Year % 4 == 0));
}
