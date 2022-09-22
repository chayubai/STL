#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
#include <cstring>
class MyString
{
public:
	MyString(const char* s = "abc")
	{
		this->len = strlen(s);
		this->str = new char[len + 1];
		strcpy(this->str, s);

		cout << "�вι��캯�� this->str = " << str << endl;
	}
	MyString(const MyString& s)
	{
		this->len = s.len;
		this->str = new char[len + 1];
		strcpy(this->str, s.str);
		cout << "�������캯�� s.str = " << s.str << endl;
	}
	MyString& operator=(const MyString& s)
	{
		cout << "operator=���غ��� s.str = " << s.str << endl;

		//�����ֵ������������
		if (&s == this)
			return *this;
		if (this->str != NULL)
			delete[] this->str;

		this->len = s.len;
		this->str = new char[len + 1];
		strcpy(this->str, s.str);

		return *this;
	}
	~MyString()
	{
		cout << "��������  ";

		if (this->str != NULL)
		{
			cout << "��ִ��delete this->str = " << this->str << endl;

			delete[] this->str;
			this->str = NULL;
			this->len = 0;
		}
	}
private:
	char* str;
	int len = 0;
};

MyString func()//������ͨ���󣬲������ã������ص�����ֵ
{
	MyString obj("mike");
	cout << "&obj = " << (void*)&obj << endl;
	//qt�£�����ֵ�Ż�������ֱ�ӽ�obj������ɸ�tmp
	//vs�£�debugģʽ�£�û��������ֵ�Ż�
	return obj;
}
int main()
{
	MyString tmp = func();
	cout << "&tmp = " << (void*)&tmp << endl;

	//ͬʱ��vs��qt�¹۲죬&obj��&tmp�ĵ�ַ
	//����qt������ͬ��
	//����vs���ǲ�ͬ��

	//Qt�µĽ����
	//�вι��캯�� this->str = mike					MyString obj("mike");
	//&obj = 00....
	//&tmp = 00....
	//�������� ��ִ��delete this->str = mike		MyString tmp = func();objֱ�ӹ��ɵ�tmp��main������ϣ��ͷ�tmp
	//&obj��&tmp�ĵ�ַ��ͬ

	//VS�µĽ����
	//�вι��캯�� this->str = mike					MyString obj("mike");
	//&obj = 00....
	//�������캯�� s.str = mike						return obj;������ʱ����(�¶���)��������ʱ����(�¶���)����obj��ʼ���¶��󣬵��ÿ������죬
	//�������� ��ִ��delete this->str = mike		func������ϣ�obj�ͷ�
	//&tmp = 00....
	//�������� ��ִ��delete this->str = mike		MyString tmp = func();��ʱ����ֱ�ӹ��ɵ�tmp(����һ���Ż������û�����Ż�Ӧ���ٵ���һ�ο�����һ��������ʱ����)��main������ϣ��ͷ�tmp
	//&obj��&tmp�ĵ�ַ��ͬ

	//��ֹ����ֵ�Ż�ѡ�
	//g++ xxx.cpp -fno-elide-constructors -std=c++11
	//linux�µĽ����
	//�вι��캯�� this->str = mike					MyString obj("mike");
	//&obj = 0x....
	//�������캯�� s.str = mike						return obj;������ʱ����(�¶���)����obj��ʼ���¶��󣬷�����ʱ����(�¶���)
	//�������� ��ִ��delete this->str = mike		func������ϣ�obj�ͷ�
	//�������캯�� s.str = mike						MyString tmp = func();��ʱ�����ʼ��tmp
	//�������� ��ִ��delete this->str = mike		������ʱ����
	//&tmp = 0x....
	//�������� ��ִ��delete this->str = mike		main������ϣ��ͷ�tmp

	//Ƶ�����ÿ������������������Ч�ʻ�ܵ�
	//���ʹ�ò���ʲô�������£��������Ч����ߵģ� -- �ƶ�����
	//1���ƶ����캯��
	//2���ƶ���ֵ��������غ���
	return 0;
}