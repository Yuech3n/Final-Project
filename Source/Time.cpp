/*************************************************************************
���ļ�����                 Time.cpp
������ģ���Ŀ�ġ�         ����һ��ʱ��
�������߼����ڡ�           ������ 2021.7
�����ļ�¼��               ���곿 2021.8 �����˿ɸ��ĵ�Ĭ��ʱ��
*************************************************************************/

#include "Time.hpp"
#include <iostream>
#include<string>

//��̬��Ա��ֵ
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
���������ơ�       Set
���������ܡ�       ���õ�ǰ�¼������ʱ��
��������           ʱ����
������ֵ��         ��
�������߼����ڡ�   ������ 2021.7
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

//��ֵ�����������
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
���������ơ�       Time
���������ܡ�       ��ȱʡ�Ĺ��캯��������һ������
��������           ʱ���� ��ȱʡ
������ֵ��         ��
�������߼����ڡ�   ������ 2021.7
*************************************************************************/
Time::Time(unsigned int Hour, unsigned int Minute, unsigned int Second): Hour(m_Hour), Minute(m_Minute), Second(m_Second){
    Set(Hour, Minute, Second);
}

/*************************************************************************
���������ơ�       EditDefaultTime
���������ܡ�       ����ȱʡ��Ĭ��ʱ��
��������           ʱ����
������ֵ��         ��
�������߼����ڡ�   ���곿 2021.8
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
