/*************************************************************************
【文件名】                 AdminWindow.h
【功能模块和目的】         创建管理员窗口，并通过Controler进行控制与调用底层程序
【开发者及日期】           王雨晨 2021.8
*************************************************************************/


#ifndef ADMINWINDOW_H
#define ADMINWINDOW_H
#include "AdminControler.h"

/*************************************************************************
【类名】             AdminWindow
【功能】             创建并显示管理员窗口
【接口说明】         AdminWindow(shared_ptr<User>& userptr);  创建管理员窗口并显示
                     void ShowWindow(); 显示管理员窗口
【开发者及日期】     王雨晨 2021.8
*************************************************************************/
class AdminWindow 
{
public:
    //删除无参构造函数
    AdminWindow() = delete;
    //通过指向管理员的动态指针创建管理员窗口
    AdminWindow(shared_ptr<User>& AdminPtr);
    //显示管理员窗口
    void ShowWindow();
private:
    //指向用户的指针与控制成员
    shared_ptr<User>& m_Userptr;
    AdminControler  m_Controler;
};

#endif // ADMINWINDOW_H
