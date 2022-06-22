/*************************************************************************
【文件名】                 UserWindow.cpp
【功能模块和目的】         创建用户窗口，并通过Controler进行控制与调用底层程序
【开发者及日期】           王雨晨 2021.8
*************************************************************************/
#include"UserWindow.h"
#include<stdio.h>

/*************************************************************************
【函数名称】       UserWindow
【函数功能】       创建一个用户窗口并显示
【参数】           用户
【返回值】         无
【开发者及日期】   王雨晨 2021.8
*************************************************************************/
UserWindow::UserWindow() {
	Message::LoadFromFile("Message.txt");
	ShowWindow();
}

/*************************************************************************
【函数名称】       ShowWindow
【函数功能】       显示用户窗口
【参数】           无
【返回值】         无
【开发者及日期】   王雨晨 2021.8
*************************************************************************/
void UserWindow::ShowWindow() {
	m_Controler.ShowMessage();
	cout << "Press 1 to create new message,Press 2 to filter the message,Press 0 to quit." << endl;
	string choice;
	cin >> choice;
	if (choice == string("0")) {
		return;
	}
	else if (choice == string("1")) {
		cout << "Please input the message,time( format like 20201118200000) and type(from Word,Action and Thought)" << endl;
		string content;
		string time;
		string type;
		cin >> content >> time >> type;
		bool IsCreat = m_Controler.AddMessage(content,time,type);
		if (!IsCreat) {
			system("cls");
			cout << "Creat failed" << endl;
		}
		else {
			system("cls");
			cout << "Creat successfully" << endl;

		}
	}
	//排序过滤
	else if (choice == string("2")) {
		cout << "Pleaase input time range(from...to)." << endl;
		string start;
		string end;
		cin >> start >> end;
		system("cls");
		if (m_Controler.FilterMessage(start, end)) {
			cout << "Filter succeed" << endl;
			string temp;
			cout << "Press and enter any key to return" << endl;
			cin >> temp;
			system("cls");
		}
		else {
			cout << "Filter failed" << endl;
		}
	}
	else {
		system("cls");
		cout << "wrong number";
	}
	cout << endl;
	ShowWindow();
}
