#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
//string��һ���࣬���ڲ���װ��char*����������ַ�������һ��char*�͵�������
//�ײ��Ƕ�̬˳���֧���������
#include <string>
#if 0
1��string ���캯��
string();//����һ���յ��ַ���    
	string str1;//string str1 = string();
string(const string& str);//ʹ��һ��string�����ʼ����һ��string����
	string str2 = str1;//string str2(str1);
string(const char* s);//ʹ���ַ���s��ʼ��
	string str3 = "abc";
string(int n, char c);//ʹ��n���ַ�c��ʼ�� 
	string str4(10, 'a');
#endif

void test1()
{
	string str;//����string���Ĭ�Ϲ���
	string str2 = str;//string str2(str);
	string str3 = "abc";
	string str4(10, 'a');
}

#if 0
2��string������ֵ����
string& operator=(const char* s);//char*�����ַ��� ��ֵ����ǰ���ַ���
	string str1; str1 = "abc";
string& operator=(const string& s);//���ַ���s������ǰ���ַ���
	string str2; str2 = str1;
string& operator=(char c);//�ַ���ֵ����ǰ���ַ���
	string str3; str3 = 'a';
string& assign(const char* s);//���ַ���s������ǰ���ַ���
	string str4; str4.assign("abc");
string& assign(const char* s, int n);//���ַ���s��ǰn���ַ�������ǰ���ַ���
	string str5 str5.assign("abc",2);
string& assign(const string& s);//���ַ���s������ǰ�ַ���
	string str6; str6.assign(str1);
string& assign(int n, char c);//��n���ַ�c������ǰ�ַ���
	string str7; str7.assign(10,'a');
string& assign(const string& s, int start, int n);//��s��start��ʼn���ַ���ֵ���ַ���
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
3��string��ȡ�ַ�����
char& operator[](int n);//ͨ��[]��ʽȡ�ַ�
char& at(int n);//ͨ��at������ȡ�ַ�
#endif
#include <stdexcept>
void test3()
{
	string str = "hello world";
	for (int i = 0; i < str.size(); i++)//ע�⣺strlen(char* s)
	{
		//cout << str[i] << endl;
		cout << str.at(i) << endl;
	}
	//[]��at����[]����Խ��ֱ�ӹҵ���at����Խ�磬�׳�out_of_range�쳣

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
		cout << "�쳣����" << endl;
	}

	//�޸�
	str[0] = 'C';
	str.at(1) = 'D';

}

#if 0
4��stringƴ�Ӳ���
string & operator+=(const string & str);//����+=������
string& operator+=(const char* str);//����+=������
string& operator+=(const char c);//����+=������
string& append(const char* s);//���ַ���s���ӵ���ǰ�ַ�����β
string& append(const char* s, int n);//���ַ���s��ǰn���ַ����ӵ���ǰ�ַ�����β
string& append(const string& s);//ͬoperator+=()
string& append(const string& s, int pos, int n);//���ַ���s�д�pos��ʼ��n���ַ����ӵ���ǰ�ַ�����β
string& append(int n, char c);//�ڵ�ǰ�ַ�����β���n���ַ�c
#endif
void test4()
{
	string str1 = "��";
	string str2 = "������";
	str1 += str2;
	str1 += "����";
	str1 += '��';

	str1.append("������");
	str1.append("������",1);
	str1.append(str2);
	str1.append(str2,0,1);//Ҳ���Ե���ȡ����
	str1.append(3,'��');
}

#if 0
5��string���Һ��滻
//find ����������
int find(const string & str, int pos = 0) const; //����str��һ�γ���λ��,��pos��ʼ����
int find(const char* s, int pos = 0) const;  //����s��һ�γ���λ��,��pos��ʼ����
int find(const char* s, int pos, int n) const;  //��posλ�ò���s��ǰn���ַ���һ��λ��
int find(const char c, int pos = 0) const;  //�����ַ�c��һ�γ���λ��
//rfind ����������
int rfind(const string& str, int pos = npos) const;//����str���һ��λ��,��pos��ʼ����
int rfind(const char* s, int pos = npos) const;//����s���һ�γ���λ��,��pos��ʼ����
int rfind(const char* s, int pos, int n) const;//��pos����s��ǰn���ַ����һ��λ��
int rfind(const char c, int pos = 0) const; //�����ַ�c���һ�γ���λ��
string& replace(int pos, int n, const string& str); //�滻��pos��ʼn���ַ�Ϊ�ַ���str
string& replace(int pos, int n, const char* s); //�滻��pos��ʼ��n���ַ�Ϊ�ַ���s
#endif
void test5()
{
	string str1 = "abcdefgde";
	string str2 = "de";
	int pos = str1.find(str2);
	pos = str1.find("dea");
	pos = str1.rfind("de");//�������һ�γ��ֵ�λ��

	if (pos == -1)//find���ҵ��˷����±꣬δ�ҵ�����-1
	{
		cout << "δ�ҵ��ַ���" << endl;
	}
	else
	{
		cout << "�ҵ��ַ������±�Ϊ��" << pos << endl;
	}
	str1.replace(1, 3, "111");
	str1.replace(1, 3, "111111");
}

#if 0
6��string�Ƚϲ���
/*
compare������>ʱ���� 1��<ʱ���� -1��==ʱ���� 0��
�Ƚ����ִ�Сд���Ƚ�ʱ�ο��ֵ�˳����Խǰ���ԽС��
��д��A��Сд��aС��
*/
int compare(const string & s) const;//���ַ���s�Ƚ�
int compare(const char* s) const;//���ַ���s�Ƚ�
#endif
void test6()
{
	string str1 = "bbcde";
	string str2 = "abcdef";
	if (str1.compare(str2) == 0)//���αȽ������ַ�����ÿ���ַ���ASCII��ֵ��С
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
7��string�Ӵ�
string substr(int pos = 0, int n = npos) const;//������pos��ʼ��n���ַ���ɵ��ַ���
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
//�����ַ���
#include <vector>
void test8()
{
	string str = "www.itcast.com.cn";

	vector<string> v;//��www itcast com cn���ʽ�ȡ��vector������

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
8��string�����ɾ������
string & insert(int pos, const char* s); //�����ַ���
string& insert(int pos, const string& str); //�����ַ���
string& insert(int pos, int n, char c);//��ָ��λ�ò���n���ַ�c
string& erase(int pos, int n = npos);//ɾ����Pos��ʼ��n���ַ� 
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
9��string��c - style�ַ���ת��
#endif 
void dowork(string str){}
void dowork2(const char* s){}
void test10()
{
	//string תconst char* ���תΪchar* ����ʹ��const_cast<char*>ȥ��const
	string str = "itcast";
	const char* cstr = str.c_str();//����string��ĳ�Ա����

	//const char* ת string 
	const char* s = "itcast";
	string str(s);//����string����вι���

	dowork(s);//const char*������ʽ����ת��Ϊstring

	//dowork2(str);//string��������ʽ����ת��Ϊconst char*
}

//Ϊ���޸�string�ַ��������ݣ��±������[]��at���᷵���ַ������á������ַ������ڴ汻���·���֮�󣬿��ܷ�������.
void test11()
{
	string s = "abcdefg";
	char& a = s[2];
	char& b = s[3];

	a = '1';
	b = '2';

	cout << s << endl;
	cout << (int*)s.c_str() << endl;

	//s = "pppppppppppppppppppppppp";//s���ڴ����·��䣬�����δ�ӡ��ַ�ǲ�һ����֪

	//a = '1';//�Ƿ�����
	//b = '2';//�Ƿ�����

	//cout << s << endl;
	//cout << (int*)s.c_str() << endl;

}

//дһ�������������ڲ���string�ַ����е�����Сд��ĸ����Ϊ��д��ĸ��
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