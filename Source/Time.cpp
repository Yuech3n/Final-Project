/*************************************************************************
【文件名】                 Time.cpp
【功能模块和目的】         创建一个时间
【开发者及日期】           范静涛 2021.7
【更改记录】               王雨晨 2021.8 增加了可更改的默认时间
*************************************************************************/

#include "Time.hpp"
#include <iostream>
#include<string>

//静态成员赋值
bool Time::Is24Format = true;
bool Time::IsFillByZero = true;
unsigned int Time::DefaultHour = 0;
unsigned int Time::DefaultMinute = 0;
unsigned int Time::DefaultSecond = 0;

//v0.4
///bool SetTime(unsigned int h, unsigned int m, unsigned int s, Time* pTime){
//    if (h < 24 && m < 60 && s < 60) {
//        pTime->Hour = h;
//        pTime->Minute = m;
//        pTime->Second = s;
//        return true;
//    }
//    return false;
//}


/*************************************************************************
【函数名称】       Set
【函数功能】       设置当前事件对象的时间
【参数】           时分秒
【返回值】         无
【开发者及日期】   范静涛 2021.7
*************************************************************************/
void Time::Set(unsigned int Hour, unsigned int Minute, unsigned int Second){
    if (Hour < 24 && Minute < 60 && Second < 60) {
        this->m_Hour = Hour;
        this->m_Minute = Minute;
        this->m_Second = Second;
    }
	else {
		throw(std::string("Time set error"));
	}
}

//赋值号运算符重载
Time Time::operator=(const Time& p) {
	if (this != &p) {
		this->m_Hour = p.m_Hour;
		this->m_Minute = p.m_Minute;
		this->m_Second = p.m_Second;
	}
	return *this;
}

//void Time::Show(){
//    std::cout << this->m_Hour << " : "
//              << this->m_Minute << " : "
//    << this->m_Second << std::endl;
//}

//Added from V1.1
//deleted form V1.3
//Time::Time() : Hour(m_Hour), Minute(m_Minute), Second(m_Second){
//    m_Hour = 1;
//    m_Minute = 1;
//    m_Second = 1;
//}

/*************************************************************************
【函数名称】       Time
【函数功能】       可缺省的构造函数，生成一个对象
【参数】           时分秒 可缺省
【返回值】         无
【开发者及日期】   范静涛 2021.7
*************************************************************************/
Time::Time(unsigned int Hour, unsigned int Minute, unsigned int Second): Hour(m_Hour), Minute(m_Minute), Second(m_Second){
    Set(Hour, Minute, Second);
}

/*************************************************************************
【函数名称】       EditDefaultTime
【函数功能】       更改缺省的默认时间
【参数】           时分秒
【返回值】         无
【开发者及日期】   王雨晨 2021.8
*************************************************************************/
void Time::EditDefaultTime(unsigned int Hour, unsigned int Minute, unsigned int Second) {
	if (Hour < 24 && Minute < 60 && Second < 60) {
		DefaultHour = Hour;
		DefaultMinute = Minute;
		DefaultSecond = Second;
	}
	else {
		throw(std::string("Defalut time set error"));
	}
}
