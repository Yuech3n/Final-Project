/*************************************************************************
���ļ�����                  DateTime.cpp
������ģ���Ŀ�ġ�          ����һ������ʱ��Ķ���
�������߼����ڡ�            ���곿 2021.8
*************************************************************************/

#include"DateTime.h"
#include"Date.h"
#include"Time.hpp"
#include<string>
using namespace std;


/*************************************************************************
���������ơ�        DateTime
���������ܡ�        ������������ȱʡ������һ��ʱ�����ڶ���
��������            ������ ʱ����
������ֵ��          ��
�������߼����ڡ�    ���곿 2021.8
*************************************************************************/
DateTime::DateTime(unsigned Y, unsigned Mon, unsigned D,
	unsigned H, unsigned Min, unsigned S){
	this->DatePart.Set(Y, Mon, D);
	this->TimePart.Set(H, Min, S);
}

//�������캯��
DateTime::DateTime(const DateTime& p) {
	this->DatePart = p.DatePart;
	this->TimePart = p.TimePart;
}

//��ֵ�������
DateTime DateTime::operator=(const DateTime& p) {
	if (this != &p) {
		this->DatePart = p.DatePart;
		this->TimePart = p.TimePart;
	}
	return *this;
}

/*************************************************************************
���������ơ�        ConvertToStr
���������ܡ�        ������ת��Ϊ��׼�ַ���
��������            DateTime����
������ֵ��          string���͵�ʱ���ַ�������20210805204000��
�������߼����ڡ�    ���곿 2021.8
*************************************************************************/
string DateTime::ConvertToStr(const DateTime& p) {
	//�Ƚ����ַ�����ʽ�ĸ���
	string YearStr = to_string(p.DatePart.Year);
	string MonthStr = to_string(p.DatePart.Month);
	string DayStr = to_string(p.DatePart.Day);
	string HourStr = to_string(p.TimePart.Hour);
	string MinuteStr = to_string(p.TimePart.Minute);
	string SecondStr = to_string(p.TimePart.Second);
	//��ʽͳһ
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
	//�ϲ�
	string DateTimeStr{};
	DateTimeStr += YearStr += MonthStr += DayStr += HourStr += MinuteStr += SecondStr;
	return DateTimeStr;
}

/*************************************************************************
���������ơ�        ConvertToTime
���������ܡ�        ����׼�ַ���ת��Ϊ����
��������            string���͵�ʱ���ַ���
������ֵ��          DateTime����
�������߼����ڡ�    ���곿 2021.8
*************************************************************************/
//�ѱ�׼�ַ���ת��Ϊʱ��
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

//��ϵ�ж�
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
���������ơ�        Set
���������ܡ�        ���õ�ǰ����ʱ������ֵ
��������            ������ʱ����
������ֵ��          ��
�������߼����ڡ�    ���곿 2021.8
*************************************************************************/
void DateTime::Set(unsigned Y, unsigned Mon, unsigned D,
	unsigned H, unsigned Min, unsigned S) {
	this->DatePart.Set(Y, Mon, D);
	this->TimePart.Set(H, Min, S);
}