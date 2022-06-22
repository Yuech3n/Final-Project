/*************************************************************************
���ļ�����                 LoginControler.cpp
������ģ���Ŀ�ġ�         ��¼���洰�ڿ�������ʵ�ֵ�¼������ײ�������������
�������߼����ڡ�           ������ 2021.8
�����ļ�¼��               ���곿 2021.8 �����˴�������Ա�������û����ڵĺ���
*************************************************************************/
#include "logincontroler.h"
#include "User.h"
#include "administrator.h"
#include"AdminWindow.h"
#include"UserWindow.h"

/*************************************************************************
���������ơ�       LoginControler
���������ܡ�       ����һ����¼������
��������           ��
������ֵ��         ��
�������߼����ڡ�   ������ 2021.8
*************************************************************************/
LoginControler::LoginControler()
{
    User::LoadFromFile("Users.txt");
}

/*************************************************************************
���������ơ�       Login
���������ܡ�       ��¼�û�������¼�û�ָ��ָ����
��������           string �û������룬shared_ptr<User>��¼�û�ָ��
������ֵ��         LoginResult ��¼���
�������߼����ڡ�   ������ 2021.8
*************************************************************************/
LoginResult LoginControler::Login(const string& Name,
    const string& Password, shared_ptr<User>& Login_userptr) {
    
    try {
        //��½�ɹ����ж��û�����
        shared_ptr<User> LoginedUser = User::Verify(Name, Password);
        Login_userptr = LoginedUser;
        if (LoginedUser->IsAdministrator()) {
            return LoginResult::ADMIN_LOGINED;
        }
        else {
            return LoginResult::USER_LOGINED;
        }
    }
    catch (invalid_argument e) {
        //��½ʧ�ܣ�����
        if (e.what() == string("No such user.")) {
            return LoginResult::NO_USER;
        }
        else {
            return LoginResult::WRONG_PASSWORD;
        }
    }
}

/*************************************************************************
���������ơ�       CreatAdminWindow
���������ܡ�       ����һ������Ա����
��������           ��
������ֵ��         ��
�������߼����ڡ�   ���곿 2021.8
*************************************************************************/
void LoginControler::CreatAdminWindow(shared_ptr<User> Userptr) {
    AdminWindow* NewAdminWindow = new AdminWindow(Userptr);
}

/*************************************************************************
���������ơ�       CreatUserWindow
���������ܡ�       ����һ���û�����
��������           ��
������ֵ��         ��
�������߼����ڡ�   ���곿 2021.8
*************************************************************************/
void LoginControler::CreatUserWindow() {
    UserWindow* NewUserWindow = new UserWindow();
}