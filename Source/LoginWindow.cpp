/*************************************************************************
【文件名】                 LoginWindow.cpp
【功能模块和目的】         创建登录窗口，并通过Controler进行控制与调用底层程序
【开发者及日期】           范静涛 2021.8
*************************************************************************/
#include"LoginWIndow.h"
#include<iostream>
#include"AdminWindow.h"
#include"UserWindow.h"
using namespace std;

/*************************************************************************
【函数名称】       LoginWindow
【函数功能】       创建一个登录窗口并显示
【参数】           无
【返回值】         无
【开发者及日期】   范静涛 2021.8
*************************************************************************/
LoginWindow::LoginWindow() {
	ShowWindow();
}

/*************************************************************************
【函数名称】       ShowWindow
【函数功能】       显示登录窗口
【参数】           无
【返回值】         无
【开发者及日期】   范静涛 2021.8
*************************************************************************/
void LoginWindow::ShowWindow() {
	string NameInput;
	string CodeInput;
	cout << "Please input your username and code:" << endl;
	//读取
	cin >> NameInput >> CodeInput;
	//新建一个登录用户指针
	shared_ptr<User> Userptr;
	//调用
	LoginResult Res = m_Controler.Login(NameInput, CodeInput, Userptr);
	//判断并输出提示
	system("cls");
	if (Res == LoginResult::NO_USER) {
		cout << "Error:Login failed,User name dose not exist" << endl;
		//再次输入
		ShowWindow();
	}
	else if (Res == LoginResult::WRONG_PASSWORD) {
		cout << "Error:Login failed,Wrong password input" << endl;
		//再次输入
		ShowWindow();
	}
	//管理员登录分支
	else if (Res == LoginResult::ADMIN_LOGINED) {
		cout << "Login Success,Login as administrator" << endl;
		//新建管理员窗口
		m_Controler.CreatAdminWindow(Userptr);
	}
	//普通用户登录分支
	else {
		cout << "Login Success,Login as user" << endl;
		m_Controler.CreatUserWindow();
	}
}