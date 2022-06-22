/*************************************************************************
【文件名】                 LoginControler.cpp
【功能模块和目的】         登录界面窗口控制器，实现登录窗口与底层可重用类的连接
【开发者及日期】           范静涛 2021.8
【更改记录】               王雨晨 2021.8 增加了创建管理员窗口与用户窗口的函数
*************************************************************************/
#include "logincontroler.h"
#include "User.h"
#include "administrator.h"
#include"AdminWindow.h"
#include"UserWindow.h"

/*************************************************************************
【函数名称】       LoginControler
【函数功能】       创建一个登录控制器
【参数】           无
【返回值】         无
【开发者及日期】   范静涛 2021.8
*************************************************************************/
LoginControler::LoginControler()
{
    User::LoadFromFile("Users.txt");
}

/*************************************************************************
【函数名称】       Login
【函数功能】       登录用户，将登录用户指针指向他
【参数】           string 用户名密码，shared_ptr<User>登录用户指针
【返回值】         LoginResult 登录结果
【开发者及日期】   范静涛 2021.8
*************************************************************************/
LoginResult LoginControler::Login(const string& Name,
    const string& Password, shared_ptr<User>& Login_userptr) {
    
    try {
        //登陆成功，判断用户种类
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
        //登陆失败，报错
        if (e.what() == string("No such user.")) {
            return LoginResult::NO_USER;
        }
        else {
            return LoginResult::WRONG_PASSWORD;
        }
    }
}

/*************************************************************************
【函数名称】       CreatAdminWindow
【函数功能】       创建一个管理员窗口
【参数】           无
【返回值】         无
【开发者及日期】   王雨晨 2021.8
*************************************************************************/
void LoginControler::CreatAdminWindow(shared_ptr<User> Userptr) {
    AdminWindow* NewAdminWindow = new AdminWindow(Userptr);
}

/*************************************************************************
【函数名称】       CreatUserWindow
【函数功能】       创建一个用户窗口
【参数】           无
【返回值】         无
【开发者及日期】   王雨晨 2021.8
*************************************************************************/
void LoginControler::CreatUserWindow() {
    UserWindow* NewUserWindow = new UserWindow();
}