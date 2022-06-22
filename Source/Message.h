/*************************************************************************
【文件名】                 Message.h
【功能模块和目的】         创建一个具有内容，时间，分类的对象
【开发者及日期】           王雨晨 2021.8
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
【类名】             MessageType
【功能】             建立枚举类，为信息类型提供选项
【接口说明】         无
【开发者及日期】     王雨晨 2021.8
*************************************************************************/
enum class MessageType {
	WORD,
	ACTION,
	THOUGHT
};

/*************************************************************************
【类名】             Message
【功能】             建立一个具有内容，时间，种类的信息类对象，并实现其存储，析构，
					 存入文档与从文档中读出
【接口说明】         Message(string Content,DateTime DateANDTime, MessageType Type) 
						给定内容时间种类，创建一个对象
					 CreatMessage(string Content,DateTime DateANDTime, MessageType Type)
						静态函数 给定内容时间种类，创建一个对象
					 GetStrType(const MessageType& p) 将对象的类型转化为string类型
					 OutputToStream(ostream& Stream) 将对象输出到流
					 SaveToFile(const string& FileName) 将对象保存到文档
					 LoadFromFile(const string& FileName) 将文档中存入的信息读出
					 MessageArrangment() 将All指针排序，按时间升序
					 vector<shared_ptr<Message>> MessageFilter(const DateTime& start, const DateTime& end)
						筛选某一时间内的全部信息，指针数组
【开发者及日期】     王雨晨 2021.8
*************************************************************************/
class Message {
public:
	//创建一个信息对象
	Message(string Content,DateTime DateANDTime, MessageType Type);

	//删除无参构造,不能生成没有参数的信息
	Message() = delete;

	//删除拷贝构造函数
	Message(const Message& p) = delete;

	//删除赋值号重载
	Message operator=(const Message& p) = delete;

	//静态创建一个Message对象
	static void CreatMessage(string Content, DateTime DateANDTime, MessageType Type);

	//将一个string形式的信息类型转化为枚举类 
	static MessageType ConvertStringtoType(string Type);

	//将某一对象的类型转化为string类型
	static string ConvertTypetoString(const MessageType& p);

	//输出到指定流
	void OutputToStream(ostream& Stream);

	//输出此类的m_All到cout
	static void OutToCout();

	//把某一信息对象输出到cout
	static void OutToCout(vector<shared_ptr<Message>> ThisAllMessage);

	//把信息对象保存至文档
	static void SaveToFile(const string& FileName);

	//从文件中读取保存的对象
	static void LoadFromFile(const string& FileName);

	//将所给信息按时间顺序排列
	static void MessageArrangment(vector<shared_ptr<Message>>& Messages);

	//筛选所给时间范围内的信息
	static vector<shared_ptr<Message>> MessageFilter(const DateTime& start, const DateTime& end);

	//静态常引用对象
	const string& Content;
	const MessageType& Type;
	const DateTime& Date_Time;

	//只读的Message成员
	const static vector<shared_ptr<Message>>& AllMessage;
private:
	//消息的内容，种类，时间
	string m_Content;
	MessageType m_Type;
	DateTime m_Date_Time;

	//全部信息
	static vector<shared_ptr<Message>> m_AllMessage;
};

#endif
