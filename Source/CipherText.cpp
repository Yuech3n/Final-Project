/*************************************************************************
���ļ�����                 CipherText.cpp
������ģ���Ŀ�ġ�         �Ը����ַ����ļ��ܣ��洢���ȡ
�������߼����ڡ�           ������ 2021.8
*************************************************************************/
#include <string>
using namespace std;
#include "CipherText.hpp"

/*************************************************************************
���������ơ�       CipherText
���������ܡ�       �������ģ��������Ķ���
��������           string���͵�����
������ֵ��         ��
�������߼����ڡ�   ������ 2021.8
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
���������ơ�       MakeFromCipherText
���������ܡ�       �������ģ��������Ķ���
��������           string���͵�����
������ֵ��         CipherText
�������߼����ڡ�   ������ 2021.8
*************************************************************************/
CipherText CipherText::MakeFromCipherText(const string& CipherText){
    class CipherText P1("123");
    P1.m_CipherText = CipherText;
    return P1;
}
