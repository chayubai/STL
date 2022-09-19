#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;

long double operator"" _mm(long double x) 
{
    return x / 1000; 
}
#if 0
//�β����ͣ����Ϸ�
long double operator"" _mm(double x)
{
    return x / 1000;
}
#endif
long double operator"" _m(long double x) 
{ 
    return x; 
}
long double operator"" _km(long double x)
{ 
    return x * 1000; 
}

//���� C++ 11 ��׼��ֻ����������б���ǺϷ��ģ�
//char const*
//unsigned long long
//long double
//char const*, size_t
//wchar_t const*, size_t
//char16_t const*, size_t
//char32_t const*, size_t

//����ĸ������ַ����൱���ã���Ϊ�ڶ����������Զ��ƶ�Ϊ�ַ����ĳ��ȡ�
//�Զ���������������Ҫ��operator"" xxx
//ֻ�����һ���������Σ��ڶ��������Զ����㣬�����һ�������ĳ��ȣ����ڶ���������ֵ
size_t operator"" _len(char const* str, size_t n)//�����ַ����ĳ���
{
    return n;
}
char const* operator"" _str(char const* str, size_t n)//�����ַ���
{
    return str;
}

//���ڲ���char const* ��Ӧ�ñ���Ϊԭʼ������ raw literal ��������
char const* operator"" _r(char const* str)
{
    return str;
}

int main()
{
    cout << 1.0_mm << endl; //0.001
    cout << 1.0_m << endl; //1
    cout << 1.0_km << endl; //1000

    cout << "mike"_len << endl; //���Ϊ4
    //"mike" -> str
    //n = strlen(str);
    cout << "mike"_str << endl; //���Ϊmike

    //cout << "123"_r << endl;//�������Ǵ��ַ���
    cout << 123_r << endl; //���Ϊ123

    return 0;
}
