/*************************************************************************
���ļ�����                 AdminControler.cpp
������ģ���Ŀ�ġ�         ����Ա����ϵͳ��ʵ�ֹ���Ա������������������
�������߼����ڡ�           ���곿 2021.8
*************************************************************************/

#include "admincontroler.h"
#include "User.h"
#include "Administrator.h"
#include "logincontroler.h"
/*************************************************************************
���������ơ�       AdminControler
���������ܡ�       ����һ������Ա������
��������           ָ�����Ա������ָ��
������ֵ��         ��
�������߼����ڡ�   ���곿 2021.8
*************************************************************************/
AdminControler::AdminControler(shared_ptr<User>& AdminPtr) {
    m_Userptr = AdminPtr;
}

/*************************************************************************
���������ơ�       AddaUser
���������ܡ�       �����û������룬�����û��������䴴�����
��������           string �û��� ����
������ֵ��         AddUserResult �������
�������߼����ڡ�   ���곿 2021.8
*************************************************************************/
AddUserResult AdminControler::AddaUser(const string& Name, const string& Password) {
    AddUserResult Res = AdminControler::GetAdduserResult(Name);
    if (Res == AddUserResult::Add_SUCCESSFUL) {
        Administrator* pAdmin = dynamic_cast<Administrator*>(m_Userptr.get());
        pAdmin->AddUser(Name, Password);
        User::SaveToFile("Users.txt");
    }
    return Res;
}

/*************************************************************************
���������ơ�       GetAdduserResult
���������ܡ�       �����û����������䴴�����
��������           string �û���
������ֵ��         AddUserResult �������
�������߼����ڡ�   ���곿 2021.8
*************************************************************************/
AddUserResult AdminControler::GetAdduserResult(const string& Name) {
    try {
        User::check(Name);
        return AddUserResult::Add_SUCCESSFUL;
    }
    catch (string e) {
        if (e == string("User already existed.")) {
            return AddUserResult::DUPLICATED_USERNAME;
        }
        else {
            return AddUserResult::CANNOT_ADD_ADMIN;
        }
    }
}
