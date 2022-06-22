/*************************************************************************
���ļ�����                 LoginWindow.cpp
������ģ���Ŀ�ġ�         ������¼���ڣ���ͨ��Controler���п�������õײ����
�������߼����ڡ�           ������ 2021.8
*************************************************************************/
#include"LoginWIndow.h"
#include<iostream>
#include"AdminWindow.h"
#include"UserWindow.h"
using namespace std;

/*************************************************************************
���������ơ�       LoginWindow
���������ܡ�       ����һ����¼���ڲ���ʾ
��������           ��
������ֵ��         ��
�������߼����ڡ�   ������ 2021.8
*************************************************************************/
LoginWindow::LoginWindow() {
	ShowWindow();
}

/*************************************************************************
���������ơ�       ShowWindow
���������ܡ�       ��ʾ��¼����
��������           ��
������ֵ��         ��
�������߼����ڡ�   ������ 2021.8
*************************************************************************/
void LoginWindow::ShowWindow() {
	string NameInput;
	string CodeInput;
	cout << "Please input your username and code:" << endl;
	//��ȡ
	cin >> NameInput >> CodeInput;
	//�½�һ����¼�û�ָ��
	shared_ptr<User> Userptr;
	//����
	LoginResult Res = m_Controler.Login(NameInput, CodeInput, Userptr);
	//�жϲ������ʾ
	system("cls");
	if (Res == LoginResult::NO_USER) {
		cout << "Error:Login failed,User name dose not exist" << endl;
		//�ٴ�����
		ShowWindow();
	}
	else if (Res == LoginResult::WRONG_PASSWORD) {
		cout << "Error:Login failed,Wrong password input" << endl;
		//�ٴ�����
		ShowWindow();
	}
	//����Ա��¼��֧
	else if (Res == LoginResult::ADMIN_LOGINED) {
		cout << "Login Success,Login as administrator" << endl;
		//�½�����Ա����
		m_Controler.CreatAdminWindow(Userptr);
	}
	//��ͨ�û���¼��֧
	else {
		cout << "Login Success,Login as user" << endl;
		m_Controler.CreatUserWindow();
	}
}