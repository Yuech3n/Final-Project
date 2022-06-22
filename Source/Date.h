/*************************************************************************
【文件名】                 Date.h
【功能模块和目的】         创建，编辑一个日期（年月日）
【开发者及日期】           王雨晨 2021.7
*************************************************************************/
#ifndef _DATE_H_
#define _DATE_H_
/*************************************************************************
【类名】			  Date
【功能】              创建，编辑一个日期（年月日），可以更改默认的构造日期
【接口说明】          Set(unsigned Year, unsigned Month, unsigned Day)  给定参数，设置当前对象日期
					  Date(unsigned Year = m_DefaultYear, unsigned Month = m_DefaultMonth,
					   unsigned Day = m_DefaultDay); 可缺省的构造函数，创建日期
					  EditYearRange(unsigned Min,unsigned Max) 修改合理年份的范围
					  EditDefaultDate(unsigned Year, unsigned Month, unsigned Day) 修改无参时默认的日期
					  bool IsValidDate(unsigned Year, unsigned Month, unsigned Day) 判断给定日期是否合理
					  IsValidDate() 判断当前对象是否合理
					  IsLeapYear(unsigned Year) 判断给定年份是否为闰年

【开发者及日期】     王雨晨 2021.7
*************************************************************************/
class Date {
public:
	//编辑更改当前对象的时间
	void Set(unsigned Year, unsigned Month, unsigned Day);
	//构造函数
	Date(unsigned Year = m_DefaultYear, unsigned Month = m_DefaultMonth,
		unsigned Day = m_DefaultDay);
	//拷贝构造函数
	Date(const Date& p);
	//赋值号重载
	Date operator=(const Date& p);
	//修改合理年份的范围
	static void EditYearRange(unsigned Min,unsigned Max);
	//修改默认日期
	static void EditDefaultDate(unsigned Year, unsigned Month, unsigned Day);
	//判断给定日期是否合理
	static bool IsValidDate(unsigned Year, unsigned Month, unsigned Day);
	//判断当前对象时间是否合理
	bool IsValidDate();
	//判断当前给定年份是否是闰年
	static bool IsLeapYear(unsigned Year);

	//对象年月日的常引用
	const unsigned& Year;
	const unsigned& Month;
	const unsigned& Day;
	//年份范围的常引用
	const unsigned MinYear;
	const unsigned MaxYear;
	//默认年月日的常引用
	const unsigned DefaultYear;
	const unsigned DefaultMonth;
	const unsigned DefaultDay;

private:
	//静态成员 年份范围
	static unsigned m_MinYear;
	static unsigned m_MaxYear;
	//静态成员 默认年月日
	static unsigned m_DefaultYear;
	static unsigned m_DefaultMonth;
	static unsigned m_DefaultDay;
	//对象年月日
	unsigned m_Year;
	unsigned m_Month;
	unsigned m_Day;
};
#endif // !_DATE_H_
