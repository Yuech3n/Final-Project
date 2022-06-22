/*************************************************************************
���ļ�����                 Date.cpp
������ģ���Ŀ�ġ�         �������༭һ�����ڣ������գ�
�������߼����ڡ�           ���곿 2021.7
*************************************************************************/
#include<iostream>
#include<string>
#include"Date.h"
using namespace std;
//Ĭ����ݷ�Χ
unsigned Date::m_MinYear = 1900;
unsigned Date::m_MaxYear = 9999;
//Ĭ�ϳ�ʼ��������
unsigned Date::m_DefaultYear = 1900;
unsigned Date::m_DefaultMonth = 1;
unsigned Date::m_DefaultDay = 1;

/*************************************************************************
���������ơ�       EditYearRange
���������ܡ�       �޸ĺ������ݷ�Χ
��������           ������ݵ���С�����ֵ
������ֵ��         ��
�������߼����ڡ�   ���곿 2021.7
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
���������ơ�       EditDefaultDate
���������ܡ�       �޸�Ĭ�Ϲ��������
��������           Ĭ�ϵ�������
������ֵ��         ��
�������߼����ڡ�   ���곿 2021.7
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
���������ơ�       Set
���������ܡ�       �༭���ĵ�ǰ�����ʱ��
��������           Ҫ���ĵ�������
������ֵ��         ��
�������߼����ڡ�   ���곿 2021.7
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

//���캯��
Date::Date(unsigned Year, unsigned Month, unsigned Day) : Year(m_Year), Month(m_Month), Day(m_Day),
	MinYear(m_MinYear), MaxYear(m_MaxYear),DefaultYear(m_DefaultYear), DefaultMonth(m_DefaultMonth), DefaultDay(m_DefaultDay) {
	Set(Year, Month, Day);
}
//�������캯��
Date::Date(const Date& p) : Year(m_Year), Month(m_Month), Day(m_Day),
MinYear(m_MinYear), MaxYear(m_MaxYear), DefaultYear(m_DefaultYear), DefaultMonth(m_DefaultMonth), DefaultDay(m_DefaultDay) {
	this->m_Year  = p.m_Year;
	this->m_Month = p.m_Month;
	this->m_Day   = p.m_Day;
}
//��ֵ�����������
Date Date::operator=(const Date& p) {
	if(this != &p){
		this->m_Year = p.m_Year;
		this->m_Month = p.m_Month;
		this->m_Day = p.m_Day;
	}
	return *this;
}

/*************************************************************************
���������ơ�       IsValidDate
���������ܡ�       �жϸ��������Ƿ����
��������           ������
������ֵ��         bool �Ƿ����
�������߼����ڡ�   ���곿 2021.7
*************************************************************************/
bool Date::IsValidDate(unsigned Year, unsigned Month, unsigned Day) {
	//���ж��Ƿ�������
	
	//��һ���ж��������Ƿ����������
	if (Year >= m_MinYear && Year <= m_MaxYear
		&& Month > 0 && Month < 13 && Day >0) {
		//�жϳ�������ÿ���·ݵ������Ƿ����
		if (((Month == 1 || Month == 3 || Month == 5 || Month == 7 || Month == 8 || Month == 10 || Month == 12) && Day <= 31)
			|| ((Month == 4 || Month == 6 || Month == 9 || Month == 11) && Day <= 30)) {
			return true;
		}
		//�ж϶���
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
���������ơ�       IsValidDate
���������ܡ�       �жϵ�ǰ���������Ƿ����
��������           ��
������ֵ��         bool �Ƿ����
�������߼����ڡ�   ���곿 2021.7
*************************************************************************/
bool Date::IsValidDate() {
	//���ж��Ƿ�������

//��һ���ж��������Ƿ����������
	if (Year >= m_MinYear && Year <= m_MaxYear
		&& Month > 0 && Month < 13 && Day >0) {
		//�жϳ�������ÿ���·ݵ������Ƿ����
		if (((Month == 1 || Month == 3 || Month == 5 || Month == 7 || Month == 8 || Month == 10 || Month == 12) && Day <= 31)
			|| ((Month == 4 || Month == 6 || Month == 9 || Month == 11) && Day <= 30)) {
			return true;
		}
		//�ж϶���
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
���������ơ�       IsLeapYear
���������ܡ�       �жϵ���������Ƿ�������
��������           ��
������ֵ��         bool �Ƿ�������
�������߼����ڡ�   ���곿 2021.7
*************************************************************************/
bool Date::IsLeapYear(unsigned Year) {
	return ((Year % 400 == 0) || (Year % 100 != 0 && Year % 4 == 0));
}
