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
		//�����ֵ������������
		if (&s == this)
			return *this;
		if (this->str != NULL)
			delete[] this->str;

		this->len = s.len;
		this->str = new char[len + 1];
		strcpy(this->str, s.str);

		cout << "operator=���غ��� s.str = " << s.str << endl;

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
	//�ƶ���ֵ��������غ���
	//ע�⣺�����Ƿ�const����ֵ����
	MyString& operator=(MyString&& s)
	{
		//�����ֵ������������
		if (&s == this)
			return *this;
		if (this->str != NULL)
			delete[] this->str;

		this->len = s.len;
		this->str = s.str;//������ַ��û�����������ڴ�

		//ԭ����ָ���ÿ�
		s.str = NULL;
		
		cout << "�ƶ�operator=���غ���" << endl;
		
		return *this;
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

	return obj;//MyString t = obj; ������ʱ����t������ֵ���գ�������ƶ����캯�� tmp == obj ����ʱ����(��ֵsobj)ȡ����tmp
	//func����������obj��Ҫ������������delete��ֻ�����������Ĵ���
}
int main()
{

	MyString m("bcd");//ʵ����һ������
	m = func();

	cout << "&m = " << (void*)&m << endl;

	//û���ƶ���ֵ��������غ�����VS�µĽ����
	//�вι��캯�� this->str = bcd								MyString m("bcd");
	//�вι��캯�� this->str = mike								MyString obj("mike");
	//&obj = 00....	
	//�ƶ����캯��												return obj;������ʱ���󣬵����ƶ�����
	//�������� operator=���غ��� s.str = mike					func����������obj������û��delete��m = func();��ʱ����ֵ��m����
	//�������� ��ִ��delete this->str = mike &tmp = 01....		main������������ʱ�����ͷ�
	//�������� ��ִ��delete this->str = mike					main����������m�ͷ�

	//���ƶ���ֵ��������غ�����VS�µĽ����
	//�вι��캯�� this->str = bcd
	//�вι��캯�� this->str = mike
	//&obj = 00....
	//�ƶ����캯��
	//�������� �ƶ�operator=���غ��� s.str = mike
	//�������� &tmp = 01....
	//�������� ��ִ��delete this->str = mike

	return 0;
}

/*
�Ϳ������캯�����ƣ��м�����Ҫע�⣺
��������ֵ���ķ��ű�������ֵ���÷��ţ�����&&����
��������ֵ���������ǳ�������Ϊ������Ҫ�޸���ֵ��
��������ֵ������Դ���Ӻͱ�Ǳ����޸ģ�������ֵ�����������ͻ��ͷ���Դ��ת�Ƶ��¶������ԴҲ����Ч�ˡ�

������ֵ���ú�ת�����壬��������ƺ�ʵ����ʱ��
������Ҫ��̬���������Դ���࣬Ӧ�����ת�ƹ��캯����ת�Ƹ�ֵ�����������Ӧ�ó����Ч�ʡ�
*/