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

	//�ƶ����캯��
	//ע�⣺�����Ƿ�const����ֵ����
	MyString(MyString&& tmp)
	{
		this->str = tmp.str;//������ַ��û�����������ڴ�
		this->len = tmp.len;

		//ԭ����ָ���ÿ�
		tmp.str = NULL;

		cout << "�ƶ����캯��" << endl;
	}

	~MyString()
	{
		cout << "��������  ";

		if (this->str != NULL)
		{
			cout << "��ִ��delete this->str = " << this->str;

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

	return obj;//MyString t = obj; ������ʱ����t������ֵ���գ�������ƶ����캯�� tmp == obj ����ʱ����(��ֵobj)ȡ����tmp
	//func����������obj��Ҫ������������delete��ֻ�����������Ĵ���
}
int main()
{
	//MyString tmp = func();
	//cout << "&tmp = " << (void*)&tmp << endl;

	//Ƶ�����ÿ������������������Ч�ʻ�ܵ�
	//���ʹ�ò���ʲô�������£��������Ч����ߵģ� -- �ƶ�����

	MyString&& m = func();//��ֵ���ý���,����ʱ����ȡ����m, main����������m����������delete
	//m.str = t.str m.len = t.len t.str = NULL

	cout << "&m = " << (void*)&m << endl;

	//VS�µĽ����
	//�вι��캯�� this->str = mike					MyString obj("mike");
	//&obj = 01....
	//�ƶ����캯��									return obj;������ʱ����(�¶���)��������ʱ����(�¶���)����obj��ʼ���¶���obj�����ƶ����캯��
	//�������� &m = 01....							func������ϣ�obj��������������û���ͷ�
	//�������� ��ִ��delete this->str = mike		MyString&& m = func();����ʱ����ȡ����Ϊm��main������ϣ��ͷ�m��Ҳ������ʱ����

	return 0;
}