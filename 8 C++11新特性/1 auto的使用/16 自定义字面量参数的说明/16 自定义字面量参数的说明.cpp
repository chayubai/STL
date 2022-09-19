#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;

long double operator"" _mm(long double x) 
{
    return x / 1000; 
}
#if 0
//形参类型：不合法
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

//根据 C++ 11 标准，只有下面参数列表才是合法的：
//char const*
//unsigned long long
//long double
//char const*, size_t
//wchar_t const*, size_t
//char16_t const*, size_t
//char32_t const*, size_t

//最后四个对于字符串相当有用，因为第二个参数会自动推断为字符串的长度。
//自定义字面量，名字要求operator"" xxx
//只需给第一个参数传参，第二个参数自动推算，即测第一个参数的长度，给第二个参数赋值
size_t operator"" _len(char const* str, size_t n)//返回字符串的长度
{
    return n;
}
char const* operator"" _str(char const* str, size_t n)//返回字符串
{
    return str;
}

//对于参数char const* ，应该被称为原始字面量 raw literal 操作符。
char const* operator"" _r(char const* str)
{
    return str;
}

int main()
{
    cout << 1.0_mm << endl; //0.001
    cout << 1.0_m << endl; //1
    cout << 1.0_km << endl; //1000

    cout << "mike"_len << endl; //结果为4
    //"mike" -> str
    //n = strlen(str);
    cout << "mike"_str << endl; //结果为mike

    //cout << "123"_r << endl;//报错，不是传字符串
    cout << 123_r << endl; //结果为123

    return 0;
}
