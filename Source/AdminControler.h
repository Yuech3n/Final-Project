/*************************************************************************
【文件名】                 AdminControler.h
【功能模块和目的】         管理员控制系统，实现管理员界面与可重用类的连接
【开发者及日期】           王雨晨 2021.8
*************************************************************************/


#ifndef ADMINCONTROLER_H
#define ADMINCONTROLER_H
#include "User.h"
#include "loginwindow.h"
#include "administrator.h"
#include "logincontroler.h"

/*************************************************************************
【类名】             AddUserResult
【功能】             管理员添加用户后的结果
【接口说明】         无（枚举类）
【开发者及日期】     王雨晨 2021.8
*************************************************************************/
enum class AddUserResult
{
    DUPLICATED_USERNAME,
    Add_SUCCESSFUL,
    CANNOT_ADD_ADMIN,
};


/*************************************************************************
【类名】             AdminControler
【功能】             管理员控制器，实现管理员界面与底层类的连接
【接口说明】         AdminControler(shared_ptr<User>& userptr);   创建管理员控制器
                     AddUserResult GetAdduserResult(const string& Name); 给定用户名，返回添加该用户的结果
                     AddUserResult AddaUser(const string& Name, const string& Password);
                     添加用户，返回添加结果

【开发者及日期】     王雨晨 2021.8
*************************************************************************/
class AdminControler
{
public:
    AdminControler() = delete;
    //通过指向管理员的智能指针创建一个管理员控制器对象
    AdminControler(shared_ptr<User>& AdminPtr);
    //获取某一用户名创建时所返回的结果
    static AddUserResult GetAdduserResult(const string& Name);
    //添加用户，返回结果
    AddUserResult AddaUser(const string& Name, const string& Password);
private:
    shared_ptr<User> m_Userptr;
};
#endif // ADMINCONTROLER_H
