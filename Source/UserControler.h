/*************************************************************************
【文件名】                 UserControler.h
【功能模块和目的】         用户控制系统，实现用户界面与可重用类的连接
【开发者及日期】           王雨晨 2021.8
*************************************************************************/

#ifndef _USERCONTROLER_H_
#define _USERCONTROLER_H_
#include<string>
#include "Message.h"
using namespace std;

/*************************************************************************
【类名】             Controler
【功能】             管理员控制器，实现管理员界面与底层类的连接
【接口说明】         ShowMessage();	展示当前信息（包含计数并输出）
					 AddMessage(string Content,string Time, string Type); 添加信息
					 FilterMessage(string StartTime,string EndTime); 过滤信息并按时间排序，输出	 
【开发者及日期】     王雨晨 2021.8
*************************************************************************/
class UserControler {
public:
	//展示当前Message类内的信息（包含总信息数量，各类型数量）
	void ShowMessage();

	//添加一条信息 ，返回是否成功
	bool AddMessage(string Content,string Time, string Type);

	//过滤并输出信息
	bool FilterMessage(string StartTime,string EndTime);
};


#endif // !_USERCONTROLER_H_
