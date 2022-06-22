/*************************************************************************
���ļ�����                 UserControler.cpp
������ģ���Ŀ�ġ�         �û�����ϵͳ��ʵ���û�������������������
�������߼����ڡ�           ���곿 2021.8
*************************************************************************/
#include"UserControler.h"
#include<iostream>
#include<stdio.h>

/*************************************************************************
���������ơ�       ShowMessage
���������ܡ�       չʾ��ǰMessage���ڵ���Ϣ����������Ϣ������������������
��������           ��
������ֵ��         ��
�������߼����ڡ�   ���곿 2021.8
*************************************************************************/
void UserControler::ShowMessage() {
	Message::OutToCout();
}

/*************************************************************************
���������ơ�       AddMessage
���������ܡ�       ���һ����Ϣ
��������           sting������ݣ�ʱ�䣬����
������ֵ��         bool �Ƿ���ӳɹ�
�������߼����ڡ�   ���곿 2021.8
*************************************************************************/
bool UserControler::AddMessage(string Content, string Time, string Type) {
	try
	{
		DateTime InputDateTime = DateTime::ConvertToTime(Time);
		MessageType InputType = MessageType::WORD;
		InputType = Message::ConvertStringtoType(Type);
		Message::CreatMessage(Content, InputDateTime, InputType);
		Message::SaveToFile("Message.txt");
		return true;
	}
	catch (string error)
	{
		cout << error << endl;
		return false;
	}
}

/*************************************************************************
���������ơ�       FilterMessage
���������ܡ�       ������Ϣ���������
��������           sting����ʼʱ�����ֹʱ��
������ֵ��         bool �Ƿ�ɸѡ�ɹ�
�������߼����ڡ�   ���곿 2021.8
*************************************************************************/
bool UserControler::FilterMessage(string StartTime, string EndTime) {
	try
	{
		DateTime Start = DateTime::ConvertToTime(StartTime);
		DateTime End = DateTime::ConvertToTime(EndTime);
		vector<shared_ptr<Message>> Res = Message::MessageFilter(Start, End);
		Message::OutToCout(Res); 
		cout << "----------------------------------------------------------" << endl;
		return true;
	}
	catch (string error)
	{
		system("cls");
		cout << endl;
		cout << error << endl;
		return false;
	}

}