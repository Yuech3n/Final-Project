/*************************************************************************
【文件名】                 LoginWindow.h
【功能模块和目的】         创建登录窗口，并通过Controler进行控制与调用底层程序
【开发者及日期】           范静涛 2021.8
*************************************************************************/
#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H
#include "LoginControler.h"

/*************************************************************************
【类名】             LoginWindow
【功能】             创建并显示登录窗口
【接口说明】         LoginWindow();  创建登录窗口并显示
                     void ShowWindow(); 显示登录窗口
【开发者及日期】     范静涛 2021.8
*************************************************************************/
class LoginWindow
{
public:
    //创建登录窗口并显示
    LoginWindow();
    //显示登录窗口
    void ShowWindow();
private:
    LoginControler m_Controler;
};
#endif // LOGINWINDOW_H
