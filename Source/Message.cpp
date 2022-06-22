/*************************************************************************
【文件名】                 Message.cpp
【功能模块和目的】         创建一个具有内容，时间，分类的对象
【开发者及日期】           王雨晨 2021.8
*************************************************************************/

#include<string>
#include"Message.h"
#include <algorithm>
using namespace std;


//初始化All M_All
vector<shared_ptr<Message>> Message::m_AllMessage{};
const vector<shared_ptr<Message>>& Message::AllMessage(m_AllMessage);

/*************************************************************************
【函数名称】       Message
【函数功能】       创建一个信息类对象
【参数】           信息的内容，时间日期，种类
【返回值】         无
【开发者及日期】   王雨晨 2021.8
*************************************************************************/
Message::Message(string Content,DateTime DateANDTime, MessageType Type) 
	:Content(m_Content),Type(m_Type),Date_Time(m_Date_Time){
	this->m_Content = Content;
	this->m_Date_Time = DateANDTime;
	this->m_Type = Type;
	m_AllMessage.push_back(shared_ptr<Message>(this));
}

/*************************************************************************
【函数名称】       ConvertStringtoType
【函数功能】       将一个string形式的信息类型转化为枚举类
【参数】           string类型的信息种类
【返回值】         枚举类型的信息种类
【开发者及日期】   王雨晨 2021.8
*************************************************************************/
MessageType Message::ConvertStringtoType(string Type) {
	MessageType b;
	if (Type == "Word") {
		b = MessageType::WORD;
	}
	else if (Type == "Action") {
		b = MessageType::ACTION;
	}
	else if (Type == "Thought") {
		b = MessageType::THOUGHT;
	}
	else {
		throw string("Wrong type input");
	}
	return b;
}

/*************************************************************************
【函数名称】       ConvertTypetoString
【函数功能】       将某一对象的类型转化为string类型
【参数】           对象指针
【返回值】         string 类型名
【开发者及日期】   王雨晨 2021.8
*************************************************************************/
string Message::ConvertTypetoString(const MessageType& p) {
	if (p == MessageType::WORD) {
		return "Word";
	}
	if(p == MessageType::ACTION) {
		return "Action";
	}
	else  {
		return "Thought";
	}
}


/*************************************************************************
【函数名称】       OutputToStream
【函数功能】       把某一信息对象输出到流
【参数】           流的引用
【返回值】         无
【开发者及日期】   王雨晨 2021.8
*************************************************************************/
void Message::OutputToStream(ostream& Stream) {
	Stream << m_Content << endl << DateTime::ConvertToStr(this->m_Date_Time) << endl
		<<Message::ConvertTypetoString(m_Type) << endl;
}

/*************************************************************************
【函数名称】       SaveToFile
【函数功能】       把某一信息对象存储至文档
【参数】           文件名
【返回值】         无
【开发者及日期】   王雨晨 2021.8
*************************************************************************/
void Message::SaveToFile(const string& FileName) {
	//打开
	ofstream File(FileName);
	//未打开则报错
	if (!File.is_open()) {
		throw invalid_argument("Can't Create File : " + FileName);
	}
	//定义函数对象
	auto Saver = [&File](shared_ptr<Message> Ptr) {Ptr->OutputToStream(File); };
	File << m_AllMessage.size() << endl;
	//遍历保存
	for_each(m_AllMessage.begin(), m_AllMessage.end(), Saver);
	File.close();
}

/*************************************************************************
【函数名称】       OutToCout
【函数功能】       把此类的信息对象输出至cout
【参数】           无
【返回值】         无
【开发者及日期】   王雨晨 2021.8
*************************************************************************/
void Message::OutToCout() {
	cout << "----------------------------------------------------------" << endl;
	auto Printer = [](shared_ptr<Message> Ptr) {Ptr->OutputToStream(cout); 	cout << endl; };
	cout << "Message count:" << endl;
	cout << m_AllMessage.size() << endl;
	int Count = m_AllMessage.size();
	int Action = 0;
	int Word = 0;
	int Thought = 0;
	for (int i = 0; i < Count; i++) {
		if (m_AllMessage.at(i)->Type == MessageType::ACTION) {
			Action++;
		}
		else if (m_AllMessage.at(i)->Type == MessageType::THOUGHT) {
			Thought++;
		}
		else {
			Word++;
		}
	}
	cout << "Action count:" << Action << endl;
	cout << "Thought count:" << Thought << endl;
	cout << "Word count:" << Word << endl;
	cout << endl;
	cout << "Message content:" << endl;
	cout << endl;
	for_each(m_AllMessage.begin(), m_AllMessage.end(), Printer);
	cout << "----------------------------------------------------------" << endl;
}

/*************************************************************************
【函数名称】       OutToCout
【函数功能】       把某一信息对象输出至cout
【参数】           指向信息指针
【返回值】         无
【开发者及日期】   王雨晨 2021.8
*************************************************************************/
void Message::OutToCout(vector<shared_ptr<Message>> ThisAllMessage) {
	cout << "----------------------------------------------------------" << endl;
	auto Printer = [](shared_ptr<Message> Ptr) {Ptr->OutputToStream(cout); 	cout << endl; };
	cout << "Message count:" << endl;
	cout << ThisAllMessage.size() << endl;
	int Count = ThisAllMessage.size();
	int Action = 0;
	int Word = 0;
	int Thought = 0;
	for (int i = 0; i < Count; i++) {
		if (ThisAllMessage.at(i)->Type == MessageType::ACTION) {
			Action++;
		}
		else if (ThisAllMessage.at(i)->Type == MessageType::THOUGHT) {
			Thought++;
		}
		else {
			Word++;
		}
	}
	cout << "Action count:" << Action << endl;
	cout << "Thought count:" << Thought << endl;
	cout << "Word count:" << Word << endl;
	cout << endl;
	cout << "Message content:" << endl;
	for_each(ThisAllMessage.begin(), ThisAllMessage.end(), Printer);
	cout << "----------------------------------------------------------" << endl;
}

/*************************************************************************
【函数名称】       LoadFromFile
【函数功能】       从文档中读取储存的对象
【参数】           文件名
【返回值】         无
【开发者及日期】   王雨晨 2021.8
*************************************************************************/
void Message::LoadFromFile(const string& FileName) {
	ifstream File(FileName);
	if (!File.is_open()) {
		throw invalid_argument("File Not Exist: " + FileName);
	}
	unsigned long MessageCount;
	File >> MessageCount;
	File.get();
	string Content;
	string DateANDTime;
	string Type;
	for (unsigned long i = 0 ; i < MessageCount ; i++) {
		getline(File, Content);
		getline(File, DateANDTime);
		getline(File, Type);
		DateTime a = DateTime::ConvertToTime(DateANDTime);
		MessageType b  = MessageType::WORD;
		b = Message::ConvertStringtoType(Type);
		new Message(Content,a,b);
	}
	File.close();
}

/*************************************************************************
【函数名称】       MessageFilter
【函数功能】       筛选出在所给时间日期范围内的信息对象
【参数】           起始时间日期与终止时间日期（闭区间）
【返回值】         该时间范围内的所有对象的指针的数组
【开发者及日期】   王雨晨 2021.8
*************************************************************************/
vector<shared_ptr<Message>> Message::MessageFilter( const DateTime& start , const DateTime& end) {
	if (start>end) {
		throw string("Invalid Time Input");
	}
	vector<shared_ptr<Message>> AfterFilter;
	auto Filter = [&start, &end, &AfterFilter](shared_ptr<Message> ptr) {
		if ((ptr->Date_Time > start && ptr->Date_Time < end)
			|| ptr->Date_Time == start|| ptr->Date_Time == end) {
			AfterFilter.push_back(ptr);
			
		}
	};
	for_each(Message::m_AllMessage.begin(), Message::m_AllMessage.end(), Filter);
	Message::MessageArrangment(AfterFilter);
	return AfterFilter;
}

/*************************************************************************
【函数名称】       MessageArrangment
【函数功能】       将所有创建的对象按时间顺序升序排列
【参数】           需要排序的信息数组
【返回值】         无
【开发者及日期】   王雨晨 2021.8
*************************************************************************/
 void Message::MessageArrangment(vector<shared_ptr<Message>>& Messages) {
	 auto Compare = [](shared_ptr<Message> a , shared_ptr<Message> b)-> bool {return a->Date_Time > b->Date_Time; };
	 sort(Messages.begin(),Messages.end(),Compare);
 }

 /*************************************************************************
 【函数名称】       CreatMessage
 【函数功能】       静态创建一个信息类对象
 【参数】           信息的内容，时间日期，种类
 【返回值】         无
 【开发者及日期】   王雨晨 2021.8
 *************************************************************************/
 void Message::CreatMessage(string Content, DateTime DateANDTime, MessageType Type) {
	 new Message(Content, DateANDTime, Type);
 }