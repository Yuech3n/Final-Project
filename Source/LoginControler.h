/*************************************************************************
���ļ�����                 LoginControler.h
������ģ���Ŀ�ġ�         ��¼���洰�ڿ�������ʵ�ֵ�¼������ײ�������������
�������߼����ڡ�           ������ 2021.8
�����ļ�¼��               ���곿 2021.8 �����˴�������Ա�������û����ڵĺ���
*************************************************************************/
#ifndef _LOGINCONTROLER_H_
#define _LOGINCONTROLER_H_
#include "User.h"
/*************************************************************************
��������             LoginResult
�����ܡ�             ��¼��Ľ��
���ӿ�˵����         �ޣ�ö���ࣩ
�������߼����ڡ�     ������ 2021.8
*************************************************************************/
enum class LoginResult
{
    ADMIN_LOGINED,
    USER_LOGINED,
    NO_USER,
    WRONG_PASSWORD,
};
/*************************************************************************
��������             LoginControler
�����ܡ�             ��¼���洰�ڿ�������ʵ�ֵ�¼������ײ�������������
���ӿ�˵����         LoginControler();   ������¼����������ȡ�ļ�
                     Login(const string& Name, const string& Password,
                      shared_ptr<User>& Login_userptr); ��¼�û�������¼�û�ָ��ָ����û�
                     CreatAdminWindow(shared_ptr<User> Userptr); ����AdminWindow
                     CreatUserWindow(); ����UserWindow
�������߼����ڡ�     ������ 2021.8
�����ļ�¼��         ���곿 2021.8 �����˴�������Ա�������û����ڵĺ���
*************************************************************************/
class LoginControler
{
public:
    //�������Ĺ��캯��
    LoginControler();
    //��¼�����������û�������͵�½ָ�룬���ص�½���
    LoginResult Login(const string& Name, const string& Password, shared_ptr<User>& Login_userptr);
    //��������Ա����Ա����
    void CreatAdminWindow(shared_ptr<User> Userptr);
    //�����û�����
    void CreatUserWindow();
};

#endif // LOGINCONTROLER_H
