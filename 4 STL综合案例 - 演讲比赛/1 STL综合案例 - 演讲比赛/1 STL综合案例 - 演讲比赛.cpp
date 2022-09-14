#define _CRT_SECURE_NO_WARNINGS 1
/*
用STL编程，求解这个问题
1）	请打印出所有选手的名字与参赛号，并以参赛号的升序排列。
2）	打印每一轮比赛后，小组比赛成绩和小组晋级名单

需求分析：
		1) 产生选手 （ ABCDEFGHIJKLMNOPQRSTUVWX ） 姓名、得分；选手编号

		2) 第1轮	选手抽签 选手比赛 查看比赛结果
		3) 第2轮	选手抽签 选手比赛 查看比赛结果
		4) 第3轮	选手抽签 选手比赛 查看比赛结果
*/
/*
第一步创建24个学生因为每个学生都有参赛编号，参赛编号唯一，放到map容器中 key是编号-value选手对象
vector<int>v1 第一轮参赛的编号列表 map[编号]，random_shuffle
vector<int >v2;第一轮比赛的晋级名单，作为第二轮的参赛编号名单
第二轮比赛的普级名单放到vector<int> v3;第三轮比赛参赛名单v3参赛结果前三名放到v4
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
	int m_score[3];//得分数组，有可能进入第三轮，拥有三个分数
};
void createSpeaker(vector<int>& v, map<int, Speaker>& m)
{
	string nameSeed = "ABCDEFGHIJKLMNOPQRSTUVWX";
	for (int i = 0; i < nameSeed.size(); i++)
	{
		string name = "选手";
		name += nameSeed[i];

		Speaker sp;
		sp.m_name = name;
		for (int j = 0; j < 3; j++)
		{
			sp.m_score[j] = 0;
		}

		v.push_back(i+100);//选手编号 100-123
		m.insert(make_pair(i + 100, sp));
	}
}
void speechDraw(vector<int> &v)
{
	//洗牌
	random_shuffle(v.begin(), v.end());
}
//index比赛轮数 v1存放所有选手编号 m存放选手编号和具体的选手 v2存放进入下一轮比赛，选手的编号
void speechContest(int index, vector<int>& vIn, map<int, Speaker>& m, vector<int>& vOut)
{
	//每次取6个人放入容器中
	multimap<int, int, greater<int>> groupMap;//按key从大到小排序 key分数 value编号，由于分数可能重复，所有用multimap
	int num = 0;//用于控制6名选手的数量
	//每个评委对每个选手进行打分
	for (vector<int>::iterator it = vIn.begin(); it != vIn.end(); it++)//外层循环，控制每个选手
	{
		num++;

		deque<int> d;//方便排除10个评分中的最高分和最低分
		for (int i = 0; i < 10; i++)//内存循环，控制每个选手的分数
		{
			int score = rand() % 41 + 60;
			d.push_back(score);
		}
		//排序
		sort(d.begin(), d.end());
		d.pop_back();
		d.pop_front();

		int sum = accumulate(d.begin(), d.end(), 0);

		//计算平均分
		int avg = sum / d.size();
		//将平均分放入到m容器中 *it编号 m[*it]可以对对组进行赋值，即m[key] == value 
		m[*it].m_score[index - 1] = avg;//第几轮得分  m[*it] == Speaker 

		//每6个人 取前三名

		//临时容器保存6个选手，每取6个选手进行比赛，取前三放入v2容器中
		//存放6个选手的数据
		groupMap.insert(make_pair(avg, *it));//将所有选手编号和对应的分数放入groupMap中
		if (num % 6 == 0)
		{//从groupMap每6个为一组，groupMap的定义必须放在外层函数外，否则每给一个选手打分都会初始化groupMap容器
			cout << "小组比赛成绩：" << endl;
			for (multimap<int, int, greater<int>>::iterator mit = groupMap.begin(); mit != groupMap.end(); mit++)
			{//m[mit->second].m_score == mit->first
				cout << "编号：" << mit->second << " 姓名：" << m[mit->second].m_name << " 平均分：" << m[mit->second].m_score[index - 1] << endl;
			}

			//取前三名
			int count = 0;
			for (multimap<int, int, greater<int>>::iterator mit = groupMap.begin(); mit != groupMap.end(),count <3; mit++,count++)
			{
				/*if (count >= 3)
				{
					break;
				}*/
				vOut.push_back(mit->second);
			}

			groupMap.clear();//每比完一组清空一次
		}
	}
}
void showScore(int index ,vector<int>& v,map<int,Speaker> &m)
{
	cout << "第" << index << "轮 比赛成绩如下：" << endl;

	for (map<int, Speaker>::iterator it = m.begin(); it != m.end(); it++)
	{
		cout << "选手编号：" << it->first << " 姓名：" << it->second.m_name << " 平均分：" << it->second.m_score[index - 1] << endl;
	}

	cout << "晋级选手编号：" << endl;
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;

	vector<int>::iterator it = v.begin();
	if (v.size() == 3)
	{
		cout << "冠军 " << " 编号：" << *it << " 姓名：" << m[*it].m_name << " 平均分：" << m[*it].m_score[index - 1] << endl;
		it++;
		cout << "亚军 " << " 编号：" << *it << " 姓名：" << m[*it].m_name << " 平均分：" << m[*it].m_score[index - 1] << endl;
		it++;
		cout << "季军 " << " 编号：" << *it << " 姓名：" << m[*it].m_name << " 平均分：" << m[*it].m_score[index - 1] << endl;
	}
}

int main()
{
	srand((unsigned int)time(NULL));

	vector<int> v1;//存放所有选手编号

	map<int, Speaker> m;//存放选手编号和具体的选手

	//创建选手
	createSpeaker(v1, m);
	
	//测试
	/*for (map<int, Speaker>::iterator it = m.begin(); it != m.end(); it++)
	{
		cout << "编号：" << it->first << " 姓名：" << (it->second).m_name << endl;
	}*/

	//抽签
	speechDraw(v1);

	//第一轮比赛
	vector<int> v2;//存放进入下一轮比赛，选手编号
	speechContest(1, v1, m, v2);//第一轮

	//显示比赛结果
	showScore(1,v2,m);

	//第二轮比赛
	speechDraw(v2);
	vector<int> v3;//存放进入下一轮比赛，选手编号
	speechContest(2, v2, m, v3);//第二轮
	showScore(2, v3, m);

	//第三轮比赛
	speechDraw(v3);
	vector<int> v4;//存放进入下一轮比赛，选手编号
	speechContest(3, v3, m, v4);//第三轮
	showScore(3, v4, m);

	//v4保存的是前三名，m保存的是所有选手编号和具体选手

	return 0;
}
//优化：
//1、每轮比赛结果显示用循环输出
//2、只显示本轮比赛选手的成绩
 