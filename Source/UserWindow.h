/*************************************************************************
【文件名】                 UserWindow.h
【功能模块和目的】         创建用户窗口，并通过Controler进行控制与调用底层程序
【开发者及日期】           王雨晨 2021.8
*************************************************************************/

#ifndef _USERWINDOW_H_
#define _USERWINDOW_H_
#include<vector>
#include"Message.h"
#include"UserControler.h"

/*************************************************************************
【类名】             UserWindow
【功能】             创建并显示用户窗口
【接口说明】         UserWindow();  创建用户窗口并显示
					 void ShowWindow(); 显示用户窗口
【开发者及日期】     王雨晨 2021.8
*************************************************************************/
class UserWindow {
public:
    //创建窗口
	UserWindow();

	//显示用户窗口
	void ShowWindow();
private:
	//控制成员
	UserControler m_Controler;
};

#endif 