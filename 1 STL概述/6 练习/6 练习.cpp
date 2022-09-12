#define _CRT_SECURE_NO_WARNINGS 1
/*
	有5名选手：选手ABCDE，10个评委分别对每一名选手打分，去除最高分，去除评委中最低分，取平均分。
	//1. 创建五名选手，放到vector中
	//2. 遍历vector容器，取出来每一个选手，执行for循环，可以把10个评分打分存到deque容器中
	//3. sort算法对deque容器中分数排序，pop_back pop_front去除最高和最低分
	//4. deque容器遍历一遍，累加分数，累加分数/d.size()
	//5. person.score = 平均分
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

//回调函数
bool myCompare(int v1, int v2)
{
	return v1 > v2;// 100 10 降序
}

void test()
{
	deque<int> d;
	d.push_back(20);
	d.push_back(10);
	d.push_back(40);
	d.push_back(10);

	//对于支持随机访问的迭代器的容器，都可以利用sort算法直接对其进行排序

	//默认排序是从小到大
	//sort(d.begin(), d.end());//_First起始迭代器 _Last结束迭代器

	//从大到小
	sort(d.begin(), d.end(), myCompare);//Pred - 回调函数或仿函数
	printDeque(d);
}

#include <string>
#include <vector>
#include <ctime>
//案例：评委打分
class Player
{
public:
	/*Player(string name, int score)
	{
		m_name = name;
		m_score = score;
	}*/
	Player(string name, int score) :m_name(name), m_score(score) {}
public://属性和行为分离
	string m_name;
	int m_score;//平均分
};
void createPlayer(vector<Player> &v)
{
	string nameSeed = "ABCDE";
	for (int i = 0; i < 5; i++)
	{
		string name = "选手";
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
		//当前学生进行打分
		
		//将评委的分数 放入到deque容器中
		deque<int> dScore;//不能放在外层循环外
		for (int i = 0; i < 10; i++)
		{
			int score = rand() % 41 + 60;//60 - 100
			dScore.push_back(score);
		}

		cout << it->m_name << "打分情况：" << endl;
		for (deque<int> ::iterator it = dScore.begin(); it != dScore.end(); it++)
		{
			cout << *it << " ";
		}
		cout << endl;

		//排序，从小到大
		sort(dScore.begin(), dScore.end());

		//去除最高分，最低分
		dScore.pop_back();//最高分
		dScore.pop_front();//最低分

		//总分
		int totalScore = 0;
		for (deque<int> ::iterator it = dScore.begin(); it != dScore.end(); it++)
		{
			totalScore += *it;
		}
		//利用accumulate算法计算累加总和
#if 0
		int totalScore = accumulate(dScore.begin(), dScore.end(),0);//0代表最后结果累加的起始值			
#endif
		
		//平均分
		int avg = totalScore / dScore.size();

		//设置每位选手的平均分
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
		cout << "姓名：" << (*it).m_name << " 最终平均分：" << it->m_score << endl;
	}
}

int main()
{
	//设置随机数种子
	srand((unsigned int)time(NULL));
	
	//做题时，可以将容器想象成数组的作用
	//1、创建5名选手
	vector<Player> v;//存放选手的容器
	createPlayer(v);

	 //测试选手是否创建成功
	//for (vector<Player>::iterator it = v.begin(); it != v.end(); it++)
	//{
	//	//*it == Player p
	//	cout << "姓名：" << (*it).m_name << " 分数：" << it->m_score << endl;
	//}

	//2、打分
	setScore(v);

	//3、显示平均分
	printRank(v);

	return 0;
}