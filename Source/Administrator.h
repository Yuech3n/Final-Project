/*************************************************************************
【文件名】                 Administrator.h
【功能模块和目的】         继承于用户类，创建管理员对象并实现通过管理员对用户的创建
【开发者及日期】           范敬涛
*************************************************************************/

#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H
#include "user.h"
#include "CipherText.hpp"
#include <string>
using namespace std;

/*************************************************************************
【类名】             Administrator
【功能】             通过继承于User类，实现了管理员用户的创建于添加普通用户
【接口说明】         AddUser(const string& Name, const CipherText& Password) 通过管理员创建新对象
                     Administrator（） 无参调用创建新管理员
                     IsAdministrator（） 在此类中为true

【开发者及日期】     范静涛 2021.8
*************************************************************************/

class Administrator : public User
{
public:
    //删除拷贝构造，赋值号运算符
    Administrator(const Administrator&) = delete ;
    Administrator& operator=(const Administrator&) = delete;
    //给定用户名与密码，添加一个用户
    void AddUser(const string& Name, const CipherText& Password);
    //无参创建一管理员，默认用户名与密码为Admin
    Administrator();
    //是否是管理员的虚函数，此类内为true
    bool IsAdministrator() const override;
    //用管理员的密文创建管理员
    Administrator(const CipherText& Password);
};

#endif // ADMINISTRATOR_H
