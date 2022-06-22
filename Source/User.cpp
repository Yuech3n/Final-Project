#include "user.h"
#include <string>
#include <vector>
#include <stdexcept>
#include <algorithm>
#include <memory>
#include <fstream>
#include "administrator.h"
using namespace std;

//��̬��Ա��ʼ��
vector<shared_ptr<User>> User::m_All{};

/*************************************************************************
���������ơ�       User
���������ܡ�       ����һ���û�����
��������           �û����û�����������ʽ������
������ֵ��         ��
�������߼����ڡ�   ���곿 2021.8
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
���������ơ�       AddUser
���������ܡ�       ����һ���û�����
��������           �û����û�����������ʽ������
������ֵ��         ��
�������߼����ڡ�   ���곿 2021.8
*************************************************************************/
void User::AddUser(const string& Name, const CipherText& Password){
    new User(Name, Password);
}

/*************************************************************************
���������ơ�       IsExist
���������ܡ�       �ж������û����Ƿ����
��������           string��ʽ���û���
������ֵ��         bool
�������߼����ڡ�   ���곿 2021.8
*************************************************************************/
bool User::IsExist(const string& Name) {
    auto Finder = [&Name](shared_ptr<User> ptr)->bool{return (ptr->m_Name == Name);};
    auto it = find_if(m_All.begin(), m_All.end(), Finder);
    return (it != m_All.end());
}

/*************************************************************************
���������ơ�       IsAdministrator
���������ܡ�       �ж϶����Ƿ�Ϊ����Ա �麯��
��������           ��
������ֵ��         bool �˴�Ϊfalse
�������߼����ڡ�   ���곿 2021.8
*************************************************************************/
bool User::IsAdministrator() const{
    return false;
}

/*************************************************************************
���������ơ�       OutputToStream
���������ܡ�       ���û��������
��������           stream
������ֵ��         ��
�������߼����ڡ�   ���곿 2021.8
*************************************************************************/
void User::OutputToStream(ostream& Stream) const{
    Stream << m_Name << endl << m_Password << endl;
}

/*************************************************************************
���������ơ�       SaveToFile
���������ܡ�       ��ȫ���û���Ϣ�������ĵ�
��������           string �ļ���
������ֵ��         ��
�������߼����ڡ�   ���곿 2021.8
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
���������ơ�       LoadFromFile
���������ܡ�       ���ĵ��ж�ȡȫ���û���Ϣ
��������           string �ļ���
������ֵ��         ��
�������߼����ڡ�   ���곿 2021.8
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
���������ơ�       Verify
���������ܡ�       �ж�������û����������Ƿ���ȷ
��������           string �û�������
������ֵ��         shared_ptr<User> ָ����û���ָ��
�������߼����ڡ�   ���곿 2021.8
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
���������ơ�       check
���������ܡ�       ����û����Ƿ����ӣ��������׳�����
��������           string �û���
������ֵ��         �ޣ�����string��ʽ�׳�����
�������߼����ڡ�   ���곿 2021.8
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