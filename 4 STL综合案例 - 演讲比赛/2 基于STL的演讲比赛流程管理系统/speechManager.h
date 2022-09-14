#pragma once
#include <iostream>
using namespace std;
#include <vector>
#include <map>
#include "speaker.h"
#include <algorithm>
#include <deque>
#include <numeric>
#include <string>
#include <fstream>
//设计演讲管理类
	//- 提供菜单界面与用户交互
	//- 对演讲比赛流程进行控制
	//- 与文件的读写交互

class SpeechManager
{
public:
	SpeechManager();

	void show_Menu();//提供菜单界面与用户交互

	//退出系统
	void exitSystem();
	
	~SpeechManager();

	//存放第一轮比赛选手的编号 容器  12人
	vector<int> v1;

	//存放第一轮晋级选手编号 容器  6人
	vector<int> v2;

	//存放胜利前三名选手编号 容器  3人
	vector<int> vVictory;

	//注意：可以用一个大容器存放三个小容器，通过大容器访问小容器

	//存放编号 以及对应的 具体选手 容器 key不会重复
	map<int, Speaker> m_Speaker;

	//记录比赛轮数
	int m_Index;

	//初始化容器和属性
	void initSpeech();

	//创建选手，所有选手分数最初为0
	void createSpeaker();

	void startSpeech();//对演讲比赛整个流程进行控制

	//抽签
	void speechDraw();
	
	//比赛
	void speechContest();

	//显示比赛结果
	void showScore();

	//与文件的读写交互
	//保存记录
	void saveRecord();

	//加载记录
	void loadRecord();

	//判断文件是否为空的标志
	bool fileIsEmpty = true;

	//往届记录的容器
	map<int, vector<string>> m_Record;//key 第几届 value 字符串记录信息

	//显示往届记录
	void showRecord();

	//清空记录
	void clearRecord();
};