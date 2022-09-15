//#pragma once
#ifndef _WALL_HEAD
#define _WALL_HEAD
#include <iostream>
using namespace std;
//#include "snake.h"

class Wall {
public:
	enum {
		ROW = 26,//行
		COL = 26//列
	};
	//初始化墙壁
	void initWall();
	//展示墙壁
	void draw();
	//根据索引设置 二维数组里的内容，方便设置蛇的位置和长度
	void setWall(int x, int y, char c);
	//根据索引获取 当前位置的符号，方便设置蛇的位置和长度
	char getWall(int x, int y);

	//显示蛇的长度 - 出现问题，下次解决并实现
	/*Snake& snake;
	Wall(Snake& tempSnake);*/

private:
	char gameArray[ROW][COL];
};
#endif // !_WALL_HEAD
