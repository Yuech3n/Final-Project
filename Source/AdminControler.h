/*************************************************************************
���ļ�����                 AdminControler.h
������ģ���Ŀ�ġ�         ����Ա����ϵͳ��ʵ�ֹ���Ա������������������
�������߼����ڡ�           ���곿 2021.8
*************************************************************************/


#ifndef ADMINCONTROLER_H
#define ADMINCONTROLER_H
#include "User.h"
#include "loginwindow.h"
#include "administrator.h"
#include "logincontroler.h"

/*************************************************************************
��������             AddUserResult
�����ܡ�             ����Ա����û���Ľ��
���ӿ�˵����         �ޣ�ö���ࣩ
�������߼����ڡ�     ���곿 2021.8
*************************************************************************/
enum class AddUserResult
{
    DUPLICATED_USERNAME,
    Add_SUCCESSFUL,
    CANNOT_ADD_ADMIN,
};


/*************************************************************************
��������             AdminControler
�����ܡ�             ����Ա��������ʵ�ֹ���Ա������ײ��������
���ӿ�˵����         AdminControler(shared_ptr<User>& userptr);   ��������Ա������
                     AddUserResult GetAdduserResult(const string& Name); �����û�����������Ӹ��û��Ľ��
                     AddUserResult AddaUser(const string& Name, const string& Password);
                     ����û���������ӽ��

�������߼����ڡ�     ���곿 2021.8
*************************************************************************/
class AdminControler
{
public:
    AdminControler() = delete;
    //ͨ��ָ�����Ա������ָ�봴��һ������Ա����������
    AdminControler(shared_ptr<User>& AdminPtr);
    //��ȡĳһ�û�������ʱ�����صĽ��
    static AddUserResult GetAdduserResult(const string& Name);
    //����û������ؽ��
    AddUserResult AddaUser(const string& Name, const string& Password);
private:
    shared_ptr<User> m_Userptr;
};
#endif // ADMINCONTROLER_H
