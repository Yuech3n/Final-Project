/*************************************************************************
���ļ�����                 AdminWindow.cpp
������ģ���Ŀ�ġ�         ��������Ա���ڣ���ͨ��Controler���п�������õײ����
�������߼����ڡ�           ���곿 2021.8
*************************************************************************/
#include "adminwindow.h"
#include "User.h"
#include "admincontroler.h"
#include<string>
#include<iostream>
#include<stdio.h>
using namespace std;

/*************************************************************************
���������ơ�       AdminWindow
���������ܡ�       ����һ������Ա���ڲ���ʾ
��������           ָ�����Ա������ָ��
������ֵ��         ��
�������߼����ڡ�   ���곿 2021.8
*************************************************************************/
AdminWindow::AdminWindow(shared_ptr<User>& AdminPtr):m_Userptr(AdminPtr), m_Controler(AdminPtr){
	ShowWindow();
}
/*************************************************************************
���������ơ�       ShowWindow
���������ܡ�       ��ʾ����Ա����
��������           ��
������ֵ��         ��
�������߼����ڡ�   ���곿 2021.8
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