/*************************************************************************
【文件名】                 UserControler.cpp
【功能模块和目的】         用户控制系统，实现用户界面与可重用类的连接
【开发者及日期】           王雨晨 2021.8
*************************************************************************/
#include"UserControler.h"
#include<iostream>
#include<stdio.h>

/*************************************************************************
【函数名称】       ShowMessage
【函数功能】       展示当前Message类内的信息（包含总信息数量，各类型数量）
【参数】           无
【返回值】         无
【开发者及日期】   王雨晨 2021.8
*************************************************************************/
void UserControler::ShowMessage() {
	Message::OutToCout();
}

/*************************************************************************
【函数名称】       AddMessage
【函数功能】       添加一条信息
【参数】           sting类的内容，时间，种类
【返回值】         bool 是否添加成功
【开发者及日期】   王雨晨 2021.8
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
【函数名称】       FilterMessage
【函数功能】       过滤信息并排序，输出
【参数】           sting类起始时间与截止时间
【返回值】         bool 是否筛选成功
【开发者及日期】   王雨晨 2021.8
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