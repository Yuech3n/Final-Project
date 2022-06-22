/*************************************************************************
【文件名】                 AdminControler.cpp
【功能模块和目的】         管理员控制系统，实现管理员界面与可重用类的连接
【开发者及日期】           王雨晨 2021.8
*************************************************************************/

#include "admincontroler.h"
#include "User.h"
#include "Administrator.h"
#include "logincontroler.h"
/*************************************************************************
【函数名称】       AdminControler
【函数功能】       创建一个管理员控制器
【参数】           指向管理员的智能指针
【返回值】         无
【开发者及日期】   王雨晨 2021.8
*************************************************************************/
AdminControler::AdminControler(shared_ptr<User>& AdminPtr) {
    m_Userptr = AdminPtr;
}

/*************************************************************************
【函数名称】       AddaUser
【函数功能】       给定用户名密码，创建用户，返回其创建结果
【参数】           string 用户名 密码
【返回值】         AddUserResult 创建结果
【开发者及日期】   王雨晨 2021.8
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
【函数名称】       GetAdduserResult
【函数功能】       给定用户名，返回其创建结果
【参数】           string 用户名
【返回值】         AddUserResult 创建结果
【开发者及日期】   王雨晨 2021.8
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
