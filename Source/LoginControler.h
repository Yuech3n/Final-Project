/*************************************************************************
【文件名】                 LoginControler.h
【功能模块和目的】         登录界面窗口控制器，实现登录窗口与底层可重用类的连接
【开发者及日期】           范静涛 2021.8
【更改记录】               王雨晨 2021.8 增加了创建管理员窗口与用户窗口的函数
*************************************************************************/
#ifndef _LOGINCONTROLER_H_
#define _LOGINCONTROLER_H_
#include "User.h"
/*************************************************************************
【类名】             LoginResult
【功能】             登录后的结果
【接口说明】         无（枚举类）
【开发者及日期】     范静涛 2021.8
*************************************************************************/
enum class LoginResult
{
    ADMIN_LOGINED,
    USER_LOGINED,
    NO_USER,
    WRONG_PASSWORD,
};
/*************************************************************************
【类名】             LoginControler
【功能】             登录界面窗口控制器，实现登录窗口与底层可重用类的连接
【接口说明】         LoginControler();   创建登录控制器，读取文件
                     Login(const string& Name, const string& Password,
                      shared_ptr<User>& Login_userptr); 登录用户，将登录用户指针指向该用户
                     CreatAdminWindow(shared_ptr<User> Userptr); 创建AdminWindow
                     CreatUserWindow(); 创建UserWindow
【开发者及日期】     范静涛 2021.8
【更改记录】         王雨晨 2021.8 增加了创建管理员窗口与用户窗口的函数
*************************************************************************/
class LoginControler
{
public:
    //控制器的构造函数
    LoginControler();
    //登录操作，输入用户名密码和登陆指针，返回登陆结果
    LoginResult Login(const string& Name, const string& Password, shared_ptr<User>& Login_userptr);
    //创建管理员管理员窗口
    void CreatAdminWindow(shared_ptr<User> Userptr);
    //创建用户窗口
    void CreatUserWindow();
};

#endif // LOGINCONTROLER_H
