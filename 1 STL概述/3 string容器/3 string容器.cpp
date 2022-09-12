#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
//string是一个类，类内部封装了char*，管理这个字符串，是一个char*型的容器。
//底层是动态顺序表，支持随机访问
#include <string>
#if 0
1、string 构造函数
string();//创建一个空的字符串    
	string str1;//string str1 = string();
string(const string& str);//使用一个string对象初始化另一个string对象
	string str2 = str1;//string str2(str1);
string(const char* s);//使用字符串s初始化
	string str3 = "abc";
string(int n, char c);//使用n个字符c初始化 
	string str4(10, 'a');
#endif

void test1()
{
	string str;//调用string类的默认构造
	string str2 = str;//string str2(str);
	string str3 = "abc";
	string str4(10, 'a');
}

#if 0
2、string基本赋值操作
string& operator=(const char* s);//char*类型字符串 赋值给当前的字符串
	string str1; str1 = "abc";
string& operator=(const string& s);//把字符串s赋给当前的字符串
	string str2; str2 = str1;
string& operator=(char c);//字符赋值给当前的字符串
	string str3; str3 = 'a';
string& assign(const char* s);//把字符串s赋给当前的字符串
	string str4; str4.assign("abc");
string& assign(const char* s, int n);//把字符串s的前n个字符赋给当前的字符串
	string str5 str5.assign("abc",2);
string& assign(const string& s);//把字符串s赋给当前字符串
	string str6; str6.assign(str1);
string& assign(int n, char c);//用n个字符c赋给当前字符串
	string str7; str7.assign(10,'a');
string& assign(const string& s, int start, int n);//将s从start开始n个字符赋值给字符串
	string str8; str8.assign(str1,0,2);
#endif

void test()
{
	string str1; str1 = "abc";

	string str2; str2 = str1;

	string str3; str3 = 'a';

	string str4; str4.assign("abc");

	string str5; str5.assign("abc", 2);

	string str6; str6.assign(str1);

	string str7; str7.assign(10, 'a');

	string str8; str8.assign(str1, 0, 2);
}

#if 0
3、string存取字符操作
char& operator[](int n);//通过[]方式取字符
char& at(int n);//通过at方法获取字符
#endif
#include <stdexcept>
void test3()
{
	string str = "hello world";
	for (int i = 0; i < str.size(); i++)//注意：strlen(char* s)
	{
		//cout << str[i] << endl;
		cout << str.at(i) << endl;
	}
	//[]和at区别：[]访问越界直接挂掉，at访问越界，抛出out_of_range异常

	try
	{
		//cout << str[100] << endl;
		cout << str.at(100) << endl;
	}
	catch (out_of_range& e)
	{
		cout << e.what() << endl;
	}
	catch (...)
	{
		cout << "异常捕获" << endl;
	}

	//修改
	str[0] = 'C';
	str.at(1) = 'D';

}

#if 0
4、string拼接操作
string & operator+=(const string & str);//重载+=操作符
string& operator+=(const char* str);//重载+=操作符
string& operator+=(const char c);//重载+=操作符
string& append(const char* s);//把字符串s连接到当前字符串结尾
string& append(const char* s, int n);//把字符串s的前n个字符连接到当前字符串结尾
string& append(const string& s);//同operator+=()
string& append(const string& s, int pos, int n);//把字符串s中从pos开始的n个字符连接到当前字符串结尾
string& append(int n, char c);//在当前字符串结尾添加n个字符c
#endif
void test4()
{
	string str1 = "我";
	string str2 = "爱北京";
	str1 += str2;
	str1 += "江西";
	str1 += '的';

	str1.append("爱北京");
	str1.append("爱北京",1);
	str1.append(str2);
	str1.append(str2,0,1);//也可以当截取功能
	str1.append(3,'我');
}

#if 0
5、string查找和替换
//find 从左往右找
int find(const string & str, int pos = 0) const; //查找str第一次出现位置,从pos开始查找
int find(const char* s, int pos = 0) const;  //查找s第一次出现位置,从pos开始查找
int find(const char* s, int pos, int n) const;  //从pos位置查找s的前n个字符第一次位置
int find(const char c, int pos = 0) const;  //查找字符c第一次出现位置
//rfind 从右往左找
int rfind(const string& str, int pos = npos) const;//查找str最后一次位置,从pos开始查找
int rfind(const char* s, int pos = npos) const;//查找s最后一次出现位置,从pos开始查找
int rfind(const char* s, int pos, int n) const;//从pos查找s的前n个字符最后一次位置
int rfind(const char c, int pos = 0) const; //查找字符c最后一次出现位置
string& replace(int pos, int n, const string& str); //替换从pos开始n个字符为字符串str
string& replace(int pos, int n, const char* s); //替换从pos开始的n个字符为字符串s
#endif
void test5()
{
	string str1 = "abcdefgde";
	string str2 = "de";
	int pos = str1.find(str2);
	pos = str1.find("dea");
	pos = str1.rfind("de");//查找最后一次出现的位置

	if (pos == -1)//find，找到了返回下标，未找到返回-1
	{
		cout << "未找到字符串" << endl;
	}
	else
	{
		cout << "找到字符串，下标为：" << pos << endl;
	}
	str1.replace(1, 3, "111");
	str1.replace(1, 3, "111111");
}

#if 0
6、string比较操作
/*
compare函数在>时返回 1，<时返回 -1，==时返回 0。
比较区分大小写，比较时参考字典顺序，排越前面的越小。
大写的A比小写的a小。
*/
int compare(const string & s) const;//与字符串s比较
int compare(const char* s) const;//与字符串s比较
#endif
void test6()
{
	string str1 = "bbcde";
	string str2 = "abcdef";
	if (str1.compare(str2) == 0)//依次比较两个字符串的每个字符的ASCII码值大小
	{
		cout << "str1 == str2" << endl;
	}
	else if(str1.compare(str2) > 0)
	{
		cout << "str1 > str2" << endl;
	}
	else
	{
		cout << "str1 < str2" << endl;
	}
}
#if 0
7、string子串
string substr(int pos = 0, int n = npos) const;//返回由pos开始的n个字符组成的字符串
#endif
void test7()
{
	string str = "abcdef";
	string subStr = str.substr(0, 3);
	cout << subStr << endl;

	string email = "2946053797@qq.com";
	int pos = email.find('@');//pos = 10
	string qq = email.substr(0, pos);
	cout << qq << endl;
}
//解析字符串
#include <vector>
void test8()
{
	string str = "www.itcast.com.cn";

	vector<string> v;//将www itcast com cn单词截取到vector容器中

	int start = 0;
	int pos = -1;
	while (true)
	{
		pos = str.find('.',start);
		if (pos == -1)
		{
			string tempStr = str.substr(start, str.size() - start);
			v.push_back(tempStr);
			break;
		}
		string tempStr = str.substr(start, pos - start);
		v.push_back(tempStr);

		start = pos + 1;
	}

	for (vector<string>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << endl;
	}
}

#if 0
8、string插入和删除操作
string & insert(int pos, const char* s); //插入字符串
string& insert(int pos, const string& str); //插入字符串
string& insert(int pos, int n, char c);//在指定位置插入n个字符c
string& erase(int pos, int n = npos);//删除从Pos开始的n个字符 
#endif
void test9()
{
	string str = "hello";
	str.insert(1, "111");
	cout << str << endl;

	str.erase(1, 3);
	cout << str << endl;
}

#if 0
9、string和c - style字符串转换
#endif 
void dowork(string str){}
void dowork2(const char* s){}
void test10()
{
	//string 转const char* 如果转为char* 可以使用const_cast<char*>去掉const
	string str = "itcast";
	const char* cstr = str.c_str();//调用string类的成员函数

	//const char* 转 string 
	const char* s = "itcast";
	string str(s);//调用string类的有参构造

	dowork(s);//const char*可以隐式类型转换为string

	//dowork2(str);//string不可以隐式类型转换为const char*
}

//为了修改string字符串的内容，下标操作符[]和at都会返回字符的引用。但当字符串的内存被重新分配之后，可能发生错误.
void test11()
{
	string s = "abcdefg";
	char& a = s[2];
	char& b = s[3];

	a = '1';
	b = '2';

	cout << s << endl;
	cout << (int*)s.c_str() << endl;

	//s = "pppppppppppppppppppppppp";//s的内存重新分配，由两次打印地址是不一样可知

	//a = '1';//非法访问
	//b = '2';//非法访问

	//cout << s << endl;
	//cout << (int*)s.c_str() << endl;

}

//写一个函数，函数内部将string字符串中的所有小写字母都变为大写字母。
void test12()
{
	string str = "abCDeF";
	for (int i = 0; i < str.size(); i++)
	{
		//str[i] = toupper(str[i]);
		str[i] = tolower(str[i]);
	}
	cout << str << endl;
}
int main()
{
	//test7();
	//test8();

	//test10();
	//test11();
	return 0;
}