/*************************************************************************
���ļ�����                 Message.h
������ģ���Ŀ�ġ�         ����һ���������ݣ�ʱ�䣬����Ķ���
�������߼����ڡ�           ���곿 2021.8
*************************************************************************/

#ifndef _MESSAGE_H_
#define _MESSAGE_H_
#include<string>
#include"DateTime.h"
#include<vector>
#include<iostream>
#include<memory>
#include <fstream>
using namespace std;

/*************************************************************************
��������             MessageType
�����ܡ�             ����ö���࣬Ϊ��Ϣ�����ṩѡ��
���ӿ�˵����         ��
�������߼����ڡ�     ���곿 2021.8
*************************************************************************/
enum class MessageType {
	WORD,
	ACTION,
	THOUGHT
};

/*************************************************************************
��������             Message
�����ܡ�             ����һ���������ݣ�ʱ�䣬�������Ϣ����󣬲�ʵ����洢��������
					 �����ĵ�����ĵ��ж���
���ӿ�˵����         Message(string Content,DateTime DateANDTime, MessageType Type) 
						��������ʱ�����࣬����һ������
					 CreatMessage(string Content,DateTime DateANDTime, MessageType Type)
						��̬���� ��������ʱ�����࣬����һ������
					 GetStrType(const MessageType& p) �����������ת��Ϊstring����
					 OutputToStream(ostream& Stream) �������������
					 SaveToFile(const string& FileName) �����󱣴浽�ĵ�
					 LoadFromFile(const string& FileName) ���ĵ��д������Ϣ����
					 MessageArrangment() ��Allָ�����򣬰�ʱ������
					 vector<shared_ptr<Message>> MessageFilter(const DateTime& start, const DateTime& end)
						ɸѡĳһʱ���ڵ�ȫ����Ϣ��ָ������
�������߼����ڡ�     ���곿 2021.8
*************************************************************************/
class Message {
public:
	//����һ����Ϣ����
	Message(string Content,DateTime DateANDTime, MessageType Type);

	//ɾ���޲ι���,��������û�в�������Ϣ
	Message() = delete;

	//ɾ���������캯��
	Message(const Message& p) = delete;

	//ɾ����ֵ������
	Message operator=(const Message& p) = delete;

	//��̬����һ��Message����
	static void CreatMessage(string Content, DateTime DateANDTime, MessageType Type);

	//��һ��string��ʽ����Ϣ����ת��Ϊö���� 
	static MessageType ConvertStringtoType(string Type);

	//��ĳһ���������ת��Ϊstring����
	static string ConvertTypetoString(const MessageType& p);

	//�����ָ����
	void OutputToStream(ostream& Stream);

	//��������m_All��cout
	static void OutToCout();

	//��ĳһ��Ϣ���������cout
	static void OutToCout(vector<shared_ptr<Message>> ThisAllMessage);

	//����Ϣ���󱣴����ĵ�
	static void SaveToFile(const string& FileName);

	//���ļ��ж�ȡ����Ķ���
	static void LoadFromFile(const string& FileName);

	//��������Ϣ��ʱ��˳������
	static void MessageArrangment(vector<shared_ptr<Message>>& Messages);

	//ɸѡ����ʱ�䷶Χ�ڵ���Ϣ
	static vector<shared_ptr<Message>> MessageFilter(const DateTime& start, const DateTime& end);

	//��̬�����ö���
	const string& Content;
	const MessageType& Type;
	const DateTime& Date_Time;

	//ֻ����Message��Ա
	const static vector<shared_ptr<Message>>& AllMessage;
private:
	//��Ϣ�����ݣ����࣬ʱ��
	string m_Content;
	MessageType m_Type;
	DateTime m_Date_Time;

	//ȫ����Ϣ
	static vector<shared_ptr<Message>> m_AllMessage;
};

#endif
