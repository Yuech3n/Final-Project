/*************************************************************************
【文件名】                 AdminWindow.cpp
【功能模块和目的】         创建管理员窗口，并通过Controler进行控制与调用底层程序
【开发者及日期】           王雨晨 2021.8
*************************************************************************/
#include "adminwindow.h"
#include "User.h"
#include "admincontroler.h"
#include<string>
#include<iostream>
#include<stdio.h>
using namespace std;

/*************************************************************************
【函数名称】       AdminWindow
【函数功能】       创建一个管理员窗口并显示
【参数】           指向管理员的智能指针
【返回值】         无
【开发者及日期】   王雨晨 2021.8
*************************************************************************/
AdminWindow::AdminWindow(shared_ptr<User>& AdminPtr):m_Userptr(AdminPtr), m_Controler(AdminPtr){
	ShowWindow();
}
/*************************************************************************
【函数名称】       ShowWindow
【函数功能】       显示管理员窗口
【参数】           无
【返回值】         无
【开发者及日期】   王雨晨 2021.8
*************************************************************************/
void AdminWindow::ShowWindow() {
	string Name{};
	string Code{};
	cout << endl;
	cout << "User create" << endl;
	cout << "Please enter the username and password for this user(enter 0 0 to break)"<< endl;
	cout << endl;
	cin >> Name >> Code;
	if (Name == Code && Code =="0") {
		return;
	}
	AddUserResult Res = m_Controler.AddaUser(Name,Code);
	if (Res == AddUserResult::Add_SUCCESSFUL) {
		system("cls");
		cout << "Adding user succeeded" << endl;
	}
	else if (Res == AddUserResult::DUPLICATED_USERNAME) {
		system("cls");
		cout << "Duplicated username" << endl;
	}
	else {
		system("cls");
		cout << "Can not creat an administrator" << endl;
	}
	ShowWindow();
}