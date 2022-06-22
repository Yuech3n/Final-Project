//
//  main.cpp
//  DEMO_DAY_04_USER_XCODE
//
//  Created by Jingtao Fan on 2021/7/29.
//

#include <iostream>
#include "user.h"
#include "administrator.h"
#include "MD5.hpp"
#include"DateTime.h"
#include<string>
#include"DateTime.h"
#include"Message.h"
#include"LoginControler.h"
#include"LoginWindow.h"
#include"AdminWindow.h"
using namespace std;

int main(int argc, const char*  argv[]) {
//for first time, to create the user information file
   /* Administrator* Admin = new Administrator();
    Admin->AddUser("123", string("456"));
    Admin->AddUser("qwe", string("asd"));
    User::SaveToFile("D:/test.txt");*/

//when you have a information file ,how to use
    //User::LoadFromFile("D:/test.txt");
    //shared_ptr<User> Logined = User::Verify("Admin", string("Admin"));
    //cout << Logined->IsAdministrator() << endl;

    LoginWindow login;
 }
