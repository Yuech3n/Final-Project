#include "user.h"
#include <string>
#include <vector>
#include <stdexcept>
#include <algorithm>
#include <memory>
#include <fstream>
#include "administrator.h"
using namespace std;

//静态成员初始化
vector<shared_ptr<User>> User::m_All{};

/*************************************************************************
【函数名称】       User
【函数功能】       创建一个用户对象
【参数】           用户的用户名与密文形式的密码
【返回值】         无
【开发者及日期】   王雨晨 2021.8
*************************************************************************/
User::User(const string& Name, const CipherText& Password) : m_Password(Password){
    auto Finder = [&Name](shared_ptr<User> ptr)->bool{return (ptr->m_Name == Name);};
    auto it = find_if(m_All.begin(), m_All.end(), Finder);
    if (it != m_All.end()) {
        if ((*it)->IsAdministrator()) {
            throw string("Administrator exists.");
        }
        else {
            throw string("Duplicate username");
        }
    }
    m_Name = Name;
    m_All.push_back(shared_ptr<User>(this));
}

/*************************************************************************
【函数名称】       AddUser
【函数功能】       创建一个用户对象
【参数】           用户的用户名与密文形式的密码
【返回值】         无
【开发者及日期】   王雨晨 2021.8
*************************************************************************/
void User::AddUser(const string& Name, const CipherText& Password){
    new User(Name, Password);
}

/*************************************************************************
【函数名称】       IsExist
【函数功能】       判断所给用户名是否存在
【参数】           string形式的用户名
【返回值】         bool
【开发者及日期】   王雨晨 2021.8
*************************************************************************/
bool User::IsExist(const string& Name) {
    auto Finder = [&Name](shared_ptr<User> ptr)->bool{return (ptr->m_Name == Name);};
    auto it = find_if(m_All.begin(), m_All.end(), Finder);
    return (it != m_All.end());
}

/*************************************************************************
【函数名称】       IsAdministrator
【函数功能】       判断对象是否为管理员 虚函数
【参数】           无
【返回值】         bool 此处为false
【开发者及日期】   王雨晨 2021.8
*************************************************************************/
bool User::IsAdministrator() const{
    return false;
}

/*************************************************************************
【函数名称】       OutputToStream
【函数功能】       将用户输出到流
【参数】           stream
【返回值】         无
【开发者及日期】   王雨晨 2021.8
*************************************************************************/
void User::OutputToStream(ostream& Stream) const{
    Stream << m_Name << endl << m_Password << endl;
}

/*************************************************************************
【函数名称】       SaveToFile
【函数功能】       将全部用户信息保存至文档
【参数】           string 文件名
【返回值】         无
【开发者及日期】   王雨晨 2021.8
*************************************************************************/
void User::SaveToFile(const string& FileName){
    ofstream File(FileName);
    if (!File.is_open()) {
        throw invalid_argument("Can't Create File : " + FileName);
    }
    auto Saver = [&File](shared_ptr<User> Ptr){Ptr->OutputToStream(File);};
    File << m_All.size() << endl;
    for_each(m_All.begin(), m_All.end(),Saver);
    File.close();
}

/*************************************************************************
【函数名称】       LoadFromFile
【函数功能】       从文档中读取全部用户信息
【参数】           string 文件名
【返回值】         无
【开发者及日期】   王雨晨 2021.8
*************************************************************************/
void User::LoadFromFile(const string& FileName){
    ifstream File(FileName);
    if (!File.is_open()) {
        throw invalid_argument("File Not Exist: " + FileName);
    }
    unsigned long UserCount;
    File >> UserCount;
    File.get();
    if (UserCount <= 1) {
        new Administrator();
    }
    else{
        string Name;
        string Password;
        getline(File, Name);
        getline(File, Password);
        new Administrator(CipherText::MakeFromCipherText(Password));
        for (unsigned long i = 0; i < UserCount - 1; i++) {
            getline(File, Name);
            getline(File, Password);
            new User(Name, CipherText::MakeFromCipherText(Password));
        }
    }
   File.close();
}

/*************************************************************************
【函数名称】       Verify
【函数功能】       判断输入的用户名与密码是否正确
【参数】           string 用户名密码
【返回值】         shared_ptr<User> 指向该用户的指针
【开发者及日期】   王雨晨 2021.8
*************************************************************************/
shared_ptr<User> User::Verify(const string& Name, const string& Password){
    auto Finder = [&Name](shared_ptr<User> ptr)->bool{return (ptr->m_Name == Name);};
    auto it = find_if(m_All.begin(), m_All.end(), Finder);
    if (it == m_All.end()) {
        throw invalid_argument("No such user.");
    }
    else if ((*it)->m_Password != Password){
        throw invalid_argument("Wrong password.");
    }
    else {
        return *it;
    }
}

/*************************************************************************
【函数名称】       check
【函数功能】       检查用户名是否可添加，错误则抛出错误
【参数】           string 用户名
【返回值】         无（会以string形式抛出错误）
【开发者及日期】   王雨晨 2021.8
*************************************************************************/
void User::check(const string& Name) {
    auto Finder = [&Name](shared_ptr<User> ptr)->bool {return (ptr->m_Name == Name); };
    auto it = find_if(m_All.begin(), m_All.end(), Finder);
    if (it == m_All.begin()) {
        throw string("Cannot add an admin.");
    }
    else if (it != m_All.end()) {
        throw string("User already existed.");
    } 
    else {
        return;
    }
}