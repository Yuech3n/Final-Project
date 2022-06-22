/*************************************************************************
���ļ�����                 Time.hpp
������ģ���Ŀ�ġ�         ����һ��ʱ��
�������߼����ڡ�           ������ 2021.7
�����ļ�¼��               ���곿 2021.8 �����˿ɸ��ĵ�Ĭ��ʱ��
*************************************************************************/

#ifndef Time_hpp
#define Time_hpp
#include <string>
/*************************************************************************
��������              Time 
�����ܡ�              ����������һ��ʱ�����
���ӿ�˵����          Time() ��ȱʡ�Ĵ���һ��ʱ�����
                      Set()  ���õ�ǰʱ������ʱ��
�������߼����ڡ�      ������ 2021.7
�����ļ�¼��          ���곿 2021.8 �����˿ɸ��ĵ�Ĭ��ʱ��
*************************************************************************/

class Time {
public:
    //��ȱʡ�Ĺ��캯�������ɶ���
    Time(unsigned int Hour = DefaultHour, unsigned int Minute = DefaultMinute,
            unsigned int Second = DefaultSecond);

    //ʱ�����ú���
    void Set(unsigned int Hour, unsigned int Minute, unsigned int Second);
    //��ֵ������
    Time operator=(const Time& p);
    //˽�г�Ա�ĳ����ó�Ա
    const unsigned int& Hour;
    const unsigned int& Minute;
    const unsigned int& Second;
    //��ǰ���ʱ������
    static bool Is24Format;
    static bool IsFillByZero;
    
    //�༭Ĭ��ʱ��
    static void EditDefaultTime(unsigned int Hour, unsigned int Minute, unsigned int Second);
    
private:
    //˽�г�Ա������ʱ���Ա
    unsigned int m_Hour;
    unsigned int m_Minute;
    unsigned int m_Second;
    //������̬��Ĭ��ʱ��
    static unsigned int DefaultHour;
    static unsigned int DefaultMinute;
    static unsigned int DefaultSecond;
};

#endif /* Time_hpp */
