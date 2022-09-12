#define _CRT_SECURE_NO_WARNINGS 1
/*
	��5��ѡ�֣�ѡ��ABCDE��10����ί�ֱ��ÿһ��ѡ�ִ�֣�ȥ����߷֣�ȥ����ί����ͷ֣�ȡƽ���֡�
	//1. ��������ѡ�֣��ŵ�vector��
	//2. ����vector������ȡ����ÿһ��ѡ�֣�ִ��forѭ�������԰�10�����ִ�ִ浽deque������
	//3. sort�㷨��deque�����з�������pop_back pop_frontȥ����ߺ���ͷ�
	//4. deque��������һ�飬�ۼӷ������ۼӷ���/d.size()
	//5. person.score = ƽ����
*/
#include <deque>
#include<algorithm>
#include <iostream>
using namespace std;

void printDeque(const deque<int>& d)
{
	for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

//�ص�����
bool myCompare(int v1, int v2)
{
	return v1 > v2;// 100 10 ����
}

void test()
{
	deque<int> d;
	d.push_back(20);
	d.push_back(10);
	d.push_back(40);
	d.push_back(10);

	//����֧��������ʵĵ�����������������������sort�㷨ֱ�Ӷ����������

	//Ĭ�������Ǵ�С����
	//sort(d.begin(), d.end());//_First��ʼ������ _Last����������

	//�Ӵ�С
	sort(d.begin(), d.end(), myCompare);//Pred - �ص�������º���
	printDeque(d);
}

#include <string>
#include <vector>
#include <ctime>
//��������ί���
class Player
{
public:
	/*Player(string name, int score)
	{
		m_name = name;
		m_score = score;
	}*/
	Player(string name, int score) :m_name(name), m_score(score) {}
public://���Ժ���Ϊ����
	string m_name;
	int m_score;//ƽ����
};
void createPlayer(vector<Player> &v)
{
	string nameSeed = "ABCDE";
	for (int i = 0; i < 5; i++)
	{
		string name = "ѡ��";
		name += nameSeed[i];

		int score = 0;

		Player p(name, score);
		v.push_back(p);
	}
}
void setScore(vector<Player> &v)
{

	for (vector<Player> :: iterator it = v.begin(); it != v.end(); it++)
	{
		//��ǰѧ�����д��
		
		//����ί�ķ��� ���뵽deque������
		deque<int> dScore;//���ܷ������ѭ����
		for (int i = 0; i < 10; i++)
		{
			int score = rand() % 41 + 60;//60 - 100
			dScore.push_back(score);
		}

		cout << it->m_name << "��������" << endl;
		for (deque<int> ::iterator it = dScore.begin(); it != dScore.end(); it++)
		{
			cout << *it << " ";
		}
		cout << endl;

		//���򣬴�С����
		sort(dScore.begin(), dScore.end());

		//ȥ����߷֣���ͷ�
		dScore.pop_back();//��߷�
		dScore.pop_front();//��ͷ�

		//�ܷ�
		int totalScore = 0;
		for (deque<int> ::iterator it = dScore.begin(); it != dScore.end(); it++)
		{
			totalScore += *it;
		}
		//����accumulate�㷨�����ۼ��ܺ�
#if 0
		int totalScore = accumulate(dScore.begin(), dScore.end(),0);//0����������ۼӵ���ʼֵ			
#endif
		
		//ƽ����
		int avg = totalScore / dScore.size();

		//����ÿλѡ�ֵ�ƽ����
		it->m_score = avg;
	}
}

bool compare(Player& p1, Player& p2)
{
	return p1.m_score > p2.m_score;
}
void printRank(vector<Player> &v)
{
	sort(v.begin(), v.end(), compare);

	for (vector<Player>::iterator it = v.begin(); it != v.end(); it++)
	{
		//*it == Player p
		cout << "������" << (*it).m_name << " ����ƽ���֣�" << it->m_score << endl;
	}
}

int main()
{
	//�������������
	srand((unsigned int)time(NULL));
	
	//����ʱ�����Խ�������������������
	//1������5��ѡ��
	vector<Player> v;//���ѡ�ֵ�����
	createPlayer(v);

	 //����ѡ���Ƿ񴴽��ɹ�
	//for (vector<Player>::iterator it = v.begin(); it != v.end(); it++)
	//{
	//	//*it == Player p
	//	cout << "������" << (*it).m_name << " ������" << it->m_score << endl;
	//}

	//2�����
	setScore(v);

	//3����ʾƽ����
	printRank(v);

	return 0;
}