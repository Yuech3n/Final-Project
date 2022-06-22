/*************************************************************************
【文件名】                 Time.hpp
【功能模块和目的】         创建一个时间
【开发者及日期】           范静涛 2021.7
【更改记录】               王雨晨 2021.8 增加了可更改的默认时间
*************************************************************************/

#ifndef Time_hpp
#define Time_hpp
#include <string>
/*************************************************************************
【类名】              Time 
【功能】              创建，设置一个时间对象
【接口说明】          Time() 可缺省的创建一个时间对象
                      Set()  设置当前时间对象的时间
【开发者及日期】      范静涛 2021.7
【更改记录】          王雨晨 2021.8 增加了可更改的默认时间
*************************************************************************/

class Time {
public:
    //可缺省的构造函数，生成对象
    Time(unsigned int Hour = DefaultHour, unsigned int Minute = DefaultMinute,
            unsigned int Second = DefaultSecond);

    //时间设置函数
    void Set(unsigned int Hour, unsigned int Minute, unsigned int Second);
    //赋值号重载
    Time operator=(const Time& p);
    //私有成员的常引用成员
    const unsigned int& Hour;
    const unsigned int& Minute;
    const unsigned int& Second;
    //当前类的时间属性
    static bool Is24Format;
    static bool IsFillByZero;
    
    //编辑默认时间
    static void EditDefaultTime(unsigned int Hour, unsigned int Minute, unsigned int Second);
    
private:
    //私有成员，三个时间成员
    unsigned int m_Hour;
    unsigned int m_Minute;
    unsigned int m_Second;
    //三个静态的默认时间
    static unsigned int DefaultHour;
    static unsigned int DefaultMinute;
    static unsigned int DefaultSecond;
};

#endif /* Time_hpp */
