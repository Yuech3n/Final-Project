/*************************************************************************
���ļ�����                 User.h
������ģ���Ŀ�ġ�         ����һ���������ݣ�ʱ�䣬����Ķ���
�������߼����ڡ�           ���곿 2021.8
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
��������             User
�����ܡ�             �����û���������ת��Ϊ������ʽ�������Զ��������������ȡ��
���ӿ�˵����         IsAdministrator() �麯�����ڴ����ڷ���ֵΪ��
                     OutputToStream(ostream& Stream) �����������û���Ϣ�������
                     SaveToFile(const string& FileName) ���û���Ϣ���浽�ļ�
                     LoadFromFile(const string& FileName) ����Ϣ���ļ��ж�ȡ
                     Verify(const string& Name, const string& Password)
                     �ж������û����������Ƿ�ƥ��
                     check(const string& Name) �����û������ظ��򱨴�
�������߼����ڡ�     ���곿 2020.8
*************************************************************************/
class User
{
public:
    //��ֹuser�Լ��������û� ɾ��Ĭ�Ϲ��캯�����������캯���븳ֵ���������
    User() = delete;
    User(const User&) = delete;
    User& operator=(const User&) = delete;

    //�麯�����Ƿ�Ϊ����Ա����USer����Ϊ�١�
    virtual bool IsAdministrator() const;
    //��������û����������������������ɼ�¼��
    void OutputToStream(ostream& Stream) const;
    //������һ���������û��������뱣�����ļ��С�
    static void SaveToFile(const string& FileName);
    //���ļ����������¶�ȡ�û������Ա�˺���Ϣ
    static void LoadFromFile(const string& FileName);
    //�ж������û����������Ƿ�ƥ��
    static shared_ptr<User> Verify(const string& Name, const string& Password);
    //����û�
    static void check(const string& Name);

protected:
    //�ܱ����ĺ��ι��캯����������������ʽ�洢
    User(const string& Name, const CipherText& Password);
    //�ɹ��̳�����õĴ����û��ӿ�
    void AddUser(const string& Name, const CipherText& Password);
private:
    //��̬�������ж������û����Ƿ����
    static bool IsExist(const string& Name);
    //��̬�䳤���飬����Ϊshared_ptrָ�룬���ڴ洢���е��û�����������Զ�����
    static vector<shared_ptr<User>> m_All;
    //�û����û���������
    string m_Name;
    CipherText m_Password;
};

#endif // USER_H
