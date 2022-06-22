/*************************************************************************
���ļ�����                 AdminWindow.h
������ģ���Ŀ�ġ�         ��������Ա���ڣ���ͨ��Controler���п�������õײ����
�������߼����ڡ�           ���곿 2021.8
*************************************************************************/


#ifndef ADMINWINDOW_H
#define ADMINWINDOW_H
#include "AdminControler.h"

/*************************************************************************
��������             AdminWindow
�����ܡ�             ��������ʾ����Ա����
���ӿ�˵����         AdminWindow(shared_ptr<User>& userptr);  ��������Ա���ڲ���ʾ
                     void ShowWindow(); ��ʾ����Ա����
�������߼����ڡ�     ���곿 2021.8
*************************************************************************/
class AdminWindow 
{
public:
    //ɾ���޲ι��캯��
    AdminWindow() = delete;
    //ͨ��ָ�����Ա�Ķ�ָ̬�봴������Ա����
    AdminWindow(shared_ptr<User>& AdminPtr);
    //��ʾ����Ա����
    void ShowWindow();
private:
    //ָ���û���ָ������Ƴ�Ա
    shared_ptr<User>& m_Userptr;
    AdminControler  m_Controler;
};

#endif // ADMINWINDOW_H
