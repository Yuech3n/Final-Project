//改写以下链接，版权声明如下
//版权声明：本文为CSDN博主「haroroda」的原创文章，遵循CC 4.0 BY-SA版权协议，转载请附上原文出处链接及本声明。
//原文链接：https://blog.csdn.net/haroroda/article/details/45935099

/*************************************************************************
【文件名】                 MD5.hpp
【功能模块和目的】         将给定明文通过MD5加密规则转为密文 
【开发者及日期】           CSDN博主「haroroda」
【更改记录】               范静涛 2021.7
*************************************************************************/

#ifndef MD5_hpp
#define MD5_hpp
#include <string>
using namespace std;
/*************************************************************************
【类名】             MD5
【功能】             将给定明文转化为密文并输出
【接口说明】         MD5(const string& PlainText)  以明文创建密文对象
                     Encrypt(const string& Plaintext) 给定明文，返回加密后密文
【开发者及日期】     CSDN博主「haroroda」
【更改记录】         范静涛 2021.7
*************************************************************************/

class MD5 {
public:
    //构建函数，给定明文创建密文对象
    MD5(const string& PlainText);
    //删除无参形式构造函数
    MD5() = delete;
    //析构函数，定义为虚函数，此处为默认析构函数
    virtual ~MD5();
    //将所给明文加密并返回密文字符串
    static string Encrypt(const string& Plaintext);
protected:
    //加密算法，给定明文进行加密，返回密文
    string Process(const string& PlainText) const;
    //密文，受保护，便于被继承
    string m_CipherText;
private:
    //密文输出
    string c_out(int* a) const;
    //一大堆所需的中间功能与静态常量，可以无视
    void DecToBin(int in, int n, int* md5) const;
    void DecToBin_Coefficient(int in, int* md5) const;
    void HexToBin(char* t, int* temp) const;
    void F(int* b, int* c, int* d, int* temp1, int* temp2) const;
    void G(int* b, int* c, int* d, int* temp1, int* temp2) const;
    void H(int* b, int* c, int* d, int* temp) const;
    void I(int* b, int* c, int* d, int* temp) const;
    void AND(int* a, int* b, int* temp) const;
    void OR(int* a, int* b, int* temp) const;
    void NOT(int* a, int* temp) const;
    void XOR(int* a, int* b, int* temp) const;
    void ADD(int* a, int* b, int* temp) const;
    void move(int step, int* temp1, int* temp2) const;
    void round(int* a, int* b, int* c, int* d, int* m, int* md5, int r, char t[16][8]) const;

    static const char T_INIT_VALUE[64][8];
    static const int  M_INIT_VALUE[4][16];
    static const int  A_INIT_VALUE[2][32];
    static const int  B_INIT_VALUE[2][32];
    static const int  C_INIT_VALUE[2][32];
    static const int  D_INIT_VALUE[2][32];
};
#endif /* MD5_hpp */
#pragma once
