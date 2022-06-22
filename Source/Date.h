/*************************************************************************
���ļ�����                 Date.h
������ģ���Ŀ�ġ�         �������༭һ�����ڣ������գ�
�������߼����ڡ�           ���곿 2021.7
*************************************************************************/
#ifndef _DATE_H_
#define _DATE_H_
/*************************************************************************
��������			  Date
�����ܡ�              �������༭һ�����ڣ������գ������Ը���Ĭ�ϵĹ�������
���ӿ�˵����          Set(unsigned Year, unsigned Month, unsigned Day)  �������������õ�ǰ��������
					  Date(unsigned Year = m_DefaultYear, unsigned Month = m_DefaultMonth,
					   unsigned Day = m_DefaultDay); ��ȱʡ�Ĺ��캯������������
					  EditYearRange(unsigned Min,unsigned Max) �޸ĺ�����ݵķ�Χ
					  EditDefaultDate(unsigned Year, unsigned Month, unsigned Day) �޸��޲�ʱĬ�ϵ�����
					  bool IsValidDate(unsigned Year, unsigned Month, unsigned Day) �жϸ��������Ƿ����
					  IsValidDate() �жϵ�ǰ�����Ƿ����
					  IsLeapYear(unsigned Year) �жϸ�������Ƿ�Ϊ����

�������߼����ڡ�     ���곿 2021.7
*************************************************************************/
class Date {
public:
	//�༭���ĵ�ǰ�����ʱ��
	void Set(unsigned Year, unsigned Month, unsigned Day);
	//���캯��
	Date(unsigned Year = m_DefaultYear, unsigned Month = m_DefaultMonth,
		unsigned Day = m_DefaultDay);
	//�������캯��
	Date(const Date& p);
	//��ֵ������
	Date operator=(const Date& p);
	//�޸ĺ�����ݵķ�Χ
	static void EditYearRange(unsigned Min,unsigned Max);
	//�޸�Ĭ������
	static void EditDefaultDate(unsigned Year, unsigned Month, unsigned Day);
	//�жϸ��������Ƿ����
	static bool IsValidDate(unsigned Year, unsigned Month, unsigned Day);
	//�жϵ�ǰ����ʱ���Ƿ����
	bool IsValidDate();
	//�жϵ�ǰ��������Ƿ�������
	static bool IsLeapYear(unsigned Year);

	//���������յĳ�����
	const unsigned& Year;
	const unsigned& Month;
	const unsigned& Day;
	//��ݷ�Χ�ĳ�����
	const unsigned MinYear;
	const unsigned MaxYear;
	//Ĭ�������յĳ�����
	const unsigned DefaultYear;
	const unsigned DefaultMonth;
	const unsigned DefaultDay;

private:
	//��̬��Ա ��ݷ�Χ
	static unsigned m_MinYear;
	static unsigned m_MaxYear;
	//��̬��Ա Ĭ��������
	static unsigned m_DefaultYear;
	static unsigned m_DefaultMonth;
	static unsigned m_DefaultDay;
	//����������
	unsigned m_Year;
	unsigned m_Month;
	unsigned m_Day;
};
#endif // !_DATE_H_
