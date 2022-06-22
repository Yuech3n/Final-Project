/*************************************************************************
���ļ�����                 Administrator.h
������ģ���Ŀ�ġ�         �̳����û��࣬��������Ա����ʵ��ͨ������Ա���û��Ĵ���
�������߼����ڡ�           ������
*************************************************************************/

#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H
#include "user.h"
#include "CipherText.hpp"
#include <string>
using namespace std;

/*************************************************************************
��������             Administrator
�����ܡ�             ͨ���̳���User�࣬ʵ���˹���Ա�û��Ĵ����������ͨ�û�
���ӿ�˵����         AddUser(const string& Name, const CipherText& Password) ͨ������Ա�����¶���
                     Administrator���� �޲ε��ô����¹���Ա
                     IsAdministrator���� �ڴ�����Ϊtrue

�������߼����ڡ�     ������ 2021.8
*************************************************************************/

class Administrator : public User
{
public:
    //ɾ���������죬��ֵ�������
    Administrator(const Administrator&) = delete ;
    Administrator& operator=(const Administrator&) = delete;
    //�����û��������룬���һ���û�
    void AddUser(const string& Name, const CipherText& Password);
    //�޲δ���һ����Ա��Ĭ���û���������ΪAdmin
    Administrator();
    //�Ƿ��ǹ���Ա���麯����������Ϊtrue
    bool IsAdministrator() const override;
    //�ù���Ա�����Ĵ�������Ա
    Administrator(const CipherText& Password);
};

#endif // ADMINISTRATOR_H
