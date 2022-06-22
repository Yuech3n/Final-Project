/*************************************************************************
���ļ�����                  DateTime.h
������ģ���Ŀ�ġ�          ����һ������ʱ��Ķ���
�������߼����ڡ�            ���곿 2021.8
*************************************************************************/
#ifndef _DATETIME_H_
#define _DATETIME_H_
#include"Date.h"
#include"Time.hpp"
#include<string>
using namespace std;
/*************************************************************************
��������             DateTime
�����ܡ�             ����һ���������ڲ�����ʱ�䲿�ֵ�DateTime����
���ӿ�˵����         DateTime(unsigned Y = 1900,unsigned Mon = 1, unsigned D = 1,
						unsigned H = 0 , unsigned Min = 0, unsigned S = 0); ��ȱʡ�Ĺ��캯��������һ��������ʱ������
					 ConvertToStr(const DateTime& p) �Ѹ���ʱ������ת��Ϊ��׼�ַ�����ʽ
					 ConvertToTime(const string& p)  �ѱ�׼�ַ�����ʽ��ʱ������ת��ΪDateTime���͵Ķ���
�������߼����ڡ�     ���곿 2021.8
*************************************************************************/
class DateTime{
public:
	//������������ȱʡ��������һ��ʱ�����ڶ���
	DateTime(unsigned Y = 1900,unsigned Mon = 1, unsigned D = 1,
		unsigned H = 0 , unsigned Min = 0, unsigned S = 0);
	//�������캯��
	DateTime(const DateTime& p);
	//��ֵ�������
	DateTime operator=(const DateTime& p);
	//��datetime����ת��Ϊ��׼�ַ�����ʽʱ��
	static string ConvertToStr(const DateTime& p);
	//����׼�ַ�����ʽʱ��ת��Ϊ����
	static DateTime ConvertToTime(const string& p);
	//��������� > < ==
	bool operator>(const DateTime& p) const;
	bool operator<(const DateTime& p) const ;
	bool operator==(const DateTime& p) const;
	//���õ�ǰ�����ֵ
	void Set(unsigned Y, unsigned Mon, unsigned D,
		unsigned H, unsigned Min, unsigned S);
	//��һ��public��Date��Ա��һ��Time��Ա����װ�����Ѿ���������ɣ���Ϊpublic������ʹ���ڲ�����
	//�Լ���ȡ����
	Date DatePart;
	Time TimePart;
};
#endif
