/*************************************************************************
【文件名】                 CipherText.cpp
【功能模块和目的】         对给定字符串的加密，存储与读取
【开发者及日期】           范静涛 2021.8
*************************************************************************/
#include <string>
using namespace std;
#include "CipherText.hpp"

/*************************************************************************
【函数名称】       CipherText
【函数功能】       给定明文，创建密文对象
【参数】           string类型的明文
【返回值】         无
【开发者及日期】   范静涛 2021.8
*************************************************************************/
CipherText::CipherText(const string& Plainext) : MD5(Plainext){
 
}

bool CipherText::operator==(const string& Plaintext) {
    return m_CipherText == MD5::Encrypt(Plaintext);
}

bool CipherText::operator!=(const string& Plaintext) {
    return !operator==(Plaintext);
}

ostream& operator<<(ostream& stream, const CipherText& CipherText){
    stream << CipherText.m_CipherText;
    return stream;
}
/*************************************************************************
【函数名称】       MakeFromCipherText
【函数功能】       给定密文，创建密文对象
【参数】           string类型的密文
【返回值】         CipherText
【开发者及日期】   范静涛 2021.8
*************************************************************************/
CipherText CipherText::MakeFromCipherText(const string& CipherText){
    class CipherText P1("123");
    P1.m_CipherText = CipherText;
    return P1;
}
