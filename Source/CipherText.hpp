/*************************************************************************
���ļ�����                 CipherText.hpp
������ģ���Ŀ�ġ�         �Ը����ַ����ļ��ܣ��洢���ȡ
�������߼����ڡ�           ������ 2021.8
*************************************************************************/

#ifndef CipherText_hpp
#define CipherText_hpp
#include <string>
#include <ostream>
#include "MD5.hpp"
using namespace std;

/*************************************************************************
��������              CipherText
�����ܡ�              ʵ�ֶԸ����ַ����ļ��ܣ��洢���ȡ
���ӿ�˵����          CipherText(const string& Plainext) ͨ�������������ַ����������Ķ���
                      MakeFromCipherText(const string& CipherText) ͨ�����Ĵ������Ķ���
�������߼����ڡ�      ������ 2021.8
*************************************************************************/
class CipherText : public MD5 {
public:
    //�������ģ��������Ķ���
    CipherText(const string& Plainext);
    //�ж������Ƿ���ͬ�������������
    bool operator==(const string& Plaintext);
    bool operator!=(const string& Plaintext);
    //��ֵ����������أ���ʵ�ֽ�string���͸�ֵ����������
    CipherText operator= (const string& Plaintext);
    //��Ԫ���أ��������������
    friend ostream& operator<<(ostream& stream, const CipherText& CipherText);
    //�������ģ��������Ķ���
    static CipherText MakeFromCipherText(const string& CipherText);
};


#endif /* CipherText_hpp */
