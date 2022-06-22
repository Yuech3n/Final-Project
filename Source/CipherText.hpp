/*************************************************************************
【文件名】                 CipherText.hpp
【功能模块和目的】         对给定字符串的加密，存储与读取
【开发者及日期】           范静涛 2021.8
*************************************************************************/

#ifndef CipherText_hpp
#define CipherText_hpp
#include <string>
#include <ostream>
#include "MD5.hpp"
using namespace std;

/*************************************************************************
【类名】              CipherText
【功能】              实现对给定字符串的加密，存储与读取
【接口说明】          CipherText(const string& Plainext) 通过给定的明文字符串创建密文对象
                      MakeFromCipherText(const string& CipherText) 通过密文创建密文对象
【开发者及日期】      范静涛 2021.8
*************************************************************************/
class CipherText : public MD5 {
public:
    //给定明文，创建密文对象
    CipherText(const string& Plainext);
    //判断密码是否相同的两运算符重载
    bool operator==(const string& Plaintext);
    bool operator!=(const string& Plaintext);
    //赋值号运算符重载，可实现将string类型赋值至密文类型
    CipherText operator= (const string& Plaintext);
    //友元重载，将密文输出至流
    friend ostream& operator<<(ostream& stream, const CipherText& CipherText);
    //给定密文，创建密文对象
    static CipherText MakeFromCipherText(const string& CipherText);
};


#endif /* CipherText_hpp */
