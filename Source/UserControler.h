/*************************************************************************
���ļ�����                 UserControler.h
������ģ���Ŀ�ġ�         �û�����ϵͳ��ʵ���û�������������������
�������߼����ڡ�           ���곿 2021.8
*************************************************************************/

#ifndef _USERCONTROLER_H_
#define _USERCONTROLER_H_
#include<string>
#include "Message.h"
using namespace std;

/*************************************************************************
��������             Controler
�����ܡ�             ����Ա��������ʵ�ֹ���Ա������ײ��������
���ӿ�˵����         ShowMessage();	չʾ��ǰ��Ϣ�����������������
					 AddMessage(string Content,string Time, string Type); �����Ϣ
					 FilterMessage(string StartTime,string EndTime); ������Ϣ����ʱ���������	 
�������߼����ڡ�     ���곿 2021.8
*************************************************************************/
class UserControler {
public:
	//չʾ��ǰMessage���ڵ���Ϣ����������Ϣ������������������
	void ShowMessage();

	//���һ����Ϣ �������Ƿ�ɹ�
	bool AddMessage(string Content,string Time, string Type);

	//���˲������Ϣ
	bool FilterMessage(string StartTime,string EndTime);
};


#endif // !_USERCONTROLER_H_
