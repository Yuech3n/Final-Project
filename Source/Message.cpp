/*************************************************************************
���ļ�����                 Message.cpp
������ģ���Ŀ�ġ�         ����һ���������ݣ�ʱ�䣬����Ķ���
�������߼����ڡ�           ���곿 2021.8
*************************************************************************/

#include<string>
#include"Message.h"
#include <algorithm>
using namespace std;


//��ʼ��All M_All
vector<shared_ptr<Message>> Message::m_AllMessage{};
const vector<shared_ptr<Message>>& Message::AllMessage(m_AllMessage);

/*************************************************************************
���������ơ�       Message
���������ܡ�       ����һ����Ϣ�����
��������           ��Ϣ�����ݣ�ʱ�����ڣ�����
������ֵ��         ��
�������߼����ڡ�   ���곿 2021.8
*************************************************************************/
Message::Message(string Content,DateTime DateANDTime, MessageType Type) 
	:Content(m_Content),Type(m_Type),Date_Time(m_Date_Time){
	this->m_Content = Content;
	this->m_Date_Time = DateANDTime;
	this->m_Type = Type;
	m_AllMessage.push_back(shared_ptr<Message>(this));
}

/*************************************************************************
���������ơ�       ConvertStringtoType
���������ܡ�       ��һ��string��ʽ����Ϣ����ת��Ϊö����
��������           string���͵���Ϣ����
������ֵ��         ö�����͵���Ϣ����
�������߼����ڡ�   ���곿 2021.8
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
���������ơ�       ConvertTypetoString
���������ܡ�       ��ĳһ���������ת��Ϊstring����
��������           ����ָ��
������ֵ��         string ������
�������߼����ڡ�   ���곿 2021.8
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
���������ơ�       OutputToStream
���������ܡ�       ��ĳһ��Ϣ�����������
��������           ��������
������ֵ��         ��
�������߼����ڡ�   ���곿 2021.8
*************************************************************************/
void Message::OutputToStream(ostream& Stream) {
	Stream << m_Content << endl << DateTime::ConvertToStr(this->m_Date_Time) << endl
		<<Message::ConvertTypetoString(m_Type) << endl;
}

/*************************************************************************
���������ơ�       SaveToFile
���������ܡ�       ��ĳһ��Ϣ����洢���ĵ�
��������           �ļ���
������ֵ��         ��
�������߼����ڡ�   ���곿 2021.8
*************************************************************************/
void Message::SaveToFile(const string& FileName) {
	//��
	ofstream File(FileName);
	//δ���򱨴�
	if (!File.is_open()) {
		throw invalid_argument("Can't Create File : " + FileName);
	}
	//���庯������
	auto Saver = [&File](shared_ptr<Message> Ptr) {Ptr->OutputToStream(File); };
	File << m_AllMessage.size() << endl;
	//��������
	for_each(m_AllMessage.begin(), m_AllMessage.end(), Saver);
	File.close();
}

/*************************************************************************
���������ơ�       OutToCout
���������ܡ�       �Ѵ������Ϣ���������cout
��������           ��
������ֵ��         ��
�������߼����ڡ�   ���곿 2021.8
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
���������ơ�       OutToCout
���������ܡ�       ��ĳһ��Ϣ���������cout
��������           ָ����Ϣָ��
������ֵ��         ��
�������߼����ڡ�   ���곿 2021.8
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
���������ơ�       LoadFromFile
���������ܡ�       ���ĵ��ж�ȡ����Ķ���
��������           �ļ���
������ֵ��         ��
�������߼����ڡ�   ���곿 2021.8
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
���������ơ�       MessageFilter
���������ܡ�       ɸѡ��������ʱ�����ڷ�Χ�ڵ���Ϣ����
��������           ��ʼʱ����������ֹʱ�����ڣ������䣩
������ֵ��         ��ʱ�䷶Χ�ڵ����ж����ָ�������
�������߼����ڡ�   ���곿 2021.8
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
���������ơ�       MessageArrangment
���������ܡ�       �����д����Ķ���ʱ��˳����������
��������           ��Ҫ�������Ϣ����
������ֵ��         ��
�������߼����ڡ�   ���곿 2021.8
*************************************************************************/
 void Message::MessageArrangment(vector<shared_ptr<Message>>& Messages) {
	 auto Compare = [](shared_ptr<Message> a , shared_ptr<Message> b)-> bool {return a->Date_Time > b->Date_Time; };
	 sort(Messages.begin(),Messages.end(),Compare);
 }

 /*************************************************************************
 ���������ơ�       CreatMessage
 ���������ܡ�       ��̬����һ����Ϣ�����
 ��������           ��Ϣ�����ݣ�ʱ�����ڣ�����
 ������ֵ��         ��
 �������߼����ڡ�   ���곿 2021.8
 *************************************************************************/
 void Message::CreatMessage(string Content, DateTime DateANDTime, MessageType Type) {
	 new Message(Content, DateANDTime, Type);
 }