//snake.h
#pragma once
#include <iostream>
#include "wall.h"
#include "food.h"
using namespace std;

//蛇的组成使用带头链表实现
class Snake {
public:

	//节点
	struct Point {
		//数据域
		int x, y;
		//指针域
		Point* next;
	};
	
	//初始化蛇的样子
	void initSnake();

	//添加节点，最初用来初始化蛇，后期用于组成蛇的长度
	void addPoint(int x, int y);

	//销毁节点，对于游戏结束要销毁蛇
	void destroyPoint();
	
	Point* pHead;//蛇的头结点

	//Snake();
	//Snake(Wall& tempWall);
	Snake(Wall& tempWall, Food& tempFood);

	Wall& wall;//引用来维护wall，用于初始化设置蛇

	//删除节点 - 由于移动的时候头结点要前进一步，尾节点要删除
	void delPoint();

	enum {
		UP = 'w', DOWN = 's', LEFT = 'a', RIGHT = 'd'
	};

	//移动蛇，返回值代表移动是否成功，撞墙(或自身)移动失败。参数key代表用于移动的方向
	bool move(char key);

	Food& food;//引用来维护food，用于设置食物

	bool isRool;//判断头部是否碰到尾部构成循环的标识

	//设定难度
	//获取刷屏时间
	int getSleepTime();
	//获取蛇的身段 不包括头
	int countList();
	//获取分数 - 根据吃的食物获取分数。
	int getScore();
	//如果将分数和蛇的长度，放在墙的右侧，该如何实现？
};
