#define _CRT_SECURE_NO_WARNINGS 1
/*
��STL��̣�����������
1��	���ӡ������ѡ�ֵ�����������ţ����Բ����ŵ��������С�
2��	��ӡÿһ�ֱ�����С������ɼ���С���������

���������
		1) ����ѡ�� �� ABCDEFGHIJKLMNOPQRSTUVWX �� �������÷֣�ѡ�ֱ��

		2) ��1��	ѡ�ֳ�ǩ ѡ�ֱ��� �鿴�������
		3) ��2��	ѡ�ֳ�ǩ ѡ�ֱ��� �鿴�������
		4) ��3��	ѡ�ֳ�ǩ ѡ�ֱ��� �鿴�������
*/
/*
��һ������24��ѧ����Ϊÿ��ѧ�����в�����ţ��������Ψһ���ŵ�map������ key�Ǳ��-valueѡ�ֶ���
vector<int>v1 ��һ�ֲ����ı���б� map[���]��random_shuffle
vector<int >v2;��һ�ֱ����Ľ�����������Ϊ�ڶ��ֵĲ����������
�ڶ��ֱ������ռ������ŵ�vector<int> v3;�����ֱ�����������v3�������ǰ�����ŵ�v4
*/
#include <iostream>
using namespace std;

#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <deque>
#include <numeric>
#include <functional>
#include <ctime>
class Speaker
{
public:
	string m_name;
	int m_score[3];//�÷����飬�п��ܽ�������֣�ӵ����������
};
void createSpeaker(vector<int>& v, map<int, Speaker>& m)
{
	string nameSeed = "ABCDEFGHIJKLMNOPQRSTUVWX";
	for (int i = 0; i < nameSeed.size(); i++)
	{
		string name = "ѡ��";
		name += nameSeed[i];

		Speaker sp;
		sp.m_name = name;
		for (int j = 0; j < 3; j++)
		{
			sp.m_score[j] = 0;
		}

		v.push_back(i+100);//ѡ�ֱ�� 100-123
		m.insert(make_pair(i + 100, sp));
	}
}
void speechDraw(vector<int> &v)
{
	//ϴ��
	random_shuffle(v.begin(), v.end());
}
//index�������� v1�������ѡ�ֱ�� m���ѡ�ֱ�ź;����ѡ�� v2��Ž�����һ�ֱ�����ѡ�ֵı��
void speechContest(int index, vector<int>& vIn, map<int, Speaker>& m, vector<int>& vOut)
{
	//ÿ��ȡ6���˷���������
	multimap<int, int, greater<int>> groupMap;//��key�Ӵ�С���� key���� value��ţ����ڷ��������ظ���������multimap
	int num = 0;//���ڿ���6��ѡ�ֵ�����
	//ÿ����ί��ÿ��ѡ�ֽ��д��
	for (vector<int>::iterator it = vIn.begin(); it != vIn.end(); it++)//���ѭ��������ÿ��ѡ��
	{
		num++;

		deque<int> d;//�����ų�10�������е���߷ֺ���ͷ�
		for (int i = 0; i < 10; i++)//�ڴ�ѭ��������ÿ��ѡ�ֵķ���
		{
			int score = rand() % 41 + 60;
			d.push_back(score);
		}
		//����
		sort(d.begin(), d.end());
		d.pop_back();
		d.pop_front();

		int sum = accumulate(d.begin(), d.end(), 0);

		//����ƽ����
		int avg = sum / d.size();
		//��ƽ���ַ��뵽m������ *it��� m[*it]���ԶԶ�����и�ֵ����m[key] == value 
		m[*it].m_score[index - 1] = avg;//�ڼ��ֵ÷�  m[*it] == Speaker 

		//ÿ6���� ȡǰ����

		//��ʱ��������6��ѡ�֣�ÿȡ6��ѡ�ֽ��б�����ȡǰ������v2������
		//���6��ѡ�ֵ�����
		groupMap.insert(make_pair(avg, *it));//������ѡ�ֱ�źͶ�Ӧ�ķ�������groupMap��
		if (num % 6 == 0)
		{//��groupMapÿ6��Ϊһ�飬groupMap�Ķ�����������㺯���⣬����ÿ��һ��ѡ�ִ�ֶ����ʼ��groupMap����
			cout << "С������ɼ���" << endl;
			for (multimap<int, int, greater<int>>::iterator mit = groupMap.begin(); mit != groupMap.end(); mit++)
			{//m[mit->second].m_score == mit->first
				cout << "��ţ�" << mit->second << " ������" << m[mit->second].m_name << " ƽ���֣�" << m[mit->second].m_score[index - 1] << endl;
			}

			//ȡǰ����
			int count = 0;
			for (multimap<int, int, greater<int>>::iterator mit = groupMap.begin(); mit != groupMap.end(),count <3; mit++,count++)
			{
				/*if (count >= 3)
				{
					break;
				}*/
				vOut.push_back(mit->second);
			}

			groupMap.clear();//ÿ����һ�����һ��
		}
	}
}
void showScore(int index ,vector<int>& v,map<int,Speaker> &m)
{
	cout << "��" << index << "�� �����ɼ����£�" << endl;

	for (map<int, Speaker>::iterator it = m.begin(); it != m.end(); it++)
	{
		cout << "ѡ�ֱ�ţ�" << it->first << " ������" << it->second.m_name << " ƽ���֣�" << it->second.m_score[index - 1] << endl;
	}

	cout << "����ѡ�ֱ�ţ�" << endl;
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;

	vector<int>::iterator it = v.begin();
	if (v.size() == 3)
	{
		cout << "�ھ� " << " ��ţ�" << *it << " ������" << m[*it].m_name << " ƽ���֣�" << m[*it].m_score[index - 1] << endl;
		it++;
		cout << "�Ǿ� " << " ��ţ�" << *it << " ������" << m[*it].m_name << " ƽ���֣�" << m[*it].m_score[index - 1] << endl;
		it++;
		cout << "���� " << " ��ţ�" << *it << " ������" << m[*it].m_name << " ƽ���֣�" << m[*it].m_score[index - 1] << endl;
	}
}

int main()
{
	srand((unsigned int)time(NULL));

	vector<int> v1;//�������ѡ�ֱ��

	map<int, Speaker> m;//���ѡ�ֱ�ź;����ѡ��

	//����ѡ��
	createSpeaker(v1, m);
	
	//����
	/*for (map<int, Speaker>::iterator it = m.begin(); it != m.end(); it++)
	{
		cout << "��ţ�" << it->first << " ������" << (it->second).m_name << endl;
	}*/

	//��ǩ
	speechDraw(v1);

	//��һ�ֱ���
	vector<int> v2;//��Ž�����һ�ֱ�����ѡ�ֱ��
	speechContest(1, v1, m, v2);//��һ��

	//��ʾ�������
	showScore(1,v2,m);

	//�ڶ��ֱ���
	speechDraw(v2);
	vector<int> v3;//��Ž�����һ�ֱ�����ѡ�ֱ��
	speechContest(2, v2, m, v3);//�ڶ���
	showScore(2, v3, m);

	//�����ֱ���
	speechDraw(v3);
	vector<int> v4;//��Ž�����һ�ֱ�����ѡ�ֱ��
	speechContest(3, v3, m, v4);//������
	showScore(3, v4, m);

	//v4�������ǰ������m�����������ѡ�ֱ�ź;���ѡ��

	return 0;
}
//�Ż���
//1��ÿ�ֱ��������ʾ��ѭ�����
//2��ֻ��ʾ���ֱ���ѡ�ֵĳɼ�
 