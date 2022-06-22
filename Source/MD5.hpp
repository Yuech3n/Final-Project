//��д�������ӣ���Ȩ��������
//��Ȩ����������ΪCSDN������haroroda����ԭ�����£���ѭCC 4.0 BY-SA��ȨЭ�飬ת���븽��ԭ�ĳ������Ӽ���������
//ԭ�����ӣ�https://blog.csdn.net/haroroda/article/details/45935099

/*************************************************************************
���ļ�����                 MD5.hpp
������ģ���Ŀ�ġ�         ����������ͨ��MD5���ܹ���תΪ���� 
�������߼����ڡ�           CSDN������haroroda��
�����ļ�¼��               ������ 2021.7
*************************************************************************/

#ifndef MD5_hpp
#define MD5_hpp
#include <string>
using namespace std;
/*************************************************************************
��������             MD5
�����ܡ�             ����������ת��Ϊ���Ĳ����
���ӿ�˵����         MD5(const string& PlainText)  �����Ĵ������Ķ���
                     Encrypt(const string& Plaintext) �������ģ����ؼ��ܺ�����
�������߼����ڡ�     CSDN������haroroda��
�����ļ�¼��         ������ 2021.7
*************************************************************************/

class MD5 {
public:
    //�����������������Ĵ������Ķ���
    MD5(const string& PlainText);
    //ɾ���޲���ʽ���캯��
    MD5() = delete;
    //��������������Ϊ�麯�����˴�ΪĬ����������
    virtual ~MD5();
    //���������ļ��ܲ����������ַ���
    static string Encrypt(const string& Plaintext);
protected:
    //�����㷨���������Ľ��м��ܣ���������
    string Process(const string& PlainText) const;
    //���ģ��ܱ��������ڱ��̳�
    string m_CipherText;
private:
    //�������
    string c_out(int* a) const;
    //һ���������м书���뾲̬��������������
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
