/*************************************************************************
【文件名】                 User.h
【功能模块和目的】         创建一个具有内容，时间，分类的对象
【开发者及日期】           王雨晨 2021.8
*************************************************************************/

#ifndef USER_H
#define USER_H
#include<string>
#include<vector>
#include<iostream>
#include<memory>
#include "CipherText.hpp"
using namespace std;

/*************************************************************************
【类名】             User
【功能】             创建用户对象，密码转化为密文形式。包括对对象的输出储存与读取。
【接口说明】         IsAdministrator() 虚函数，在此类内返回值为假
                     OutputToStream(ostream& Stream) 给定流，将用户信息输出到流
                     SaveToFile(const string& FileName) 将用户信息保存到文件
                     LoadFromFile(const string& FileName) 将信息从文件中读取
                     Verify(const string& Name, const string& Password)
                     判断所给用户名与密码是否匹配
                     check(const string& Name) 查找用户，若重复则报错
【开发者及日期】     王雨晨 2020.8
*************************************************************************/
class User
{
public:
    //防止user自己创建新用户 删除默认构造函数，拷贝构造函数与赋值号运算符。
    User() = delete;
    User(const User&) = delete;
    User& operator=(const User&) = delete;

    //虚函数，是否为管理员，在USer类内为假。
    virtual bool IsAdministrator() const;
    //输出，把用户名与密码输出到流，以完成记录。
    void OutputToStream(ostream& Stream) const;
    //调用上一函数，把用户名与密码保存在文件中。
    static void SaveToFile(const string& FileName);
    //打开文件，从中重新读取用户与管理员账号信息
    static void LoadFromFile(const string& FileName);
    //判断所给用户名与密码是否匹配
    static shared_ptr<User> Verify(const string& Name, const string& Password);
    //检查用户
    static void check(const string& Name);

protected:
    //受保护的含参构造函数，密码以密文形式存储
    User(const string& Name, const CipherText& Password);
    //可供继承类调用的创建用户接口
    void AddUser(const string& Name, const CipherText& Password);
private:
    //静态函数，判断所给用户名是否存在
    static bool IsExist(const string& Name);
    //静态变长数组，内容为shared_ptr指针，用于存储所有的用户，可在最后被自动析构
    static vector<shared_ptr<User>> m_All;
    //用户的用户名与密码
    string m_Name;
    CipherText m_Password;
};

#endif // USER_H
