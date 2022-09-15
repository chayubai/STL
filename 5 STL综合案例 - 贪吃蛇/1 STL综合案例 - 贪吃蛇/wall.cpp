#define _CRT_SECURE_NO_WARNINGS 1

#include "wall.h"

void Wall::initWall()
{
	for (int i = 0; i < ROW; ++i) {
		for (int j = 0; j < COL; ++j) {
			//放墙壁
			if (i == 0 || j == 0 || i == ROW - 1 || j == COL - 1) {
				gameArray[i][j] = '*';
			}
			else
			{
				gameArray[i][j] = ' ';
			}
		}
	}
}

void Wall::draw()
{
	for (int i = 0; i < ROW; ++i) {
		for (int j = 0; j < COL; ++j) {
			cout << gameArray[i][j] << " ";//这里多输出一个空格，墙的显示效果更好
		}
		//第5行开始输出版本信息
		if (i == 5)
			cout << "created by CYB";
		else if (i == 6)
			cout << "A: left";
		else if (i == 7)
			cout << "D: right";
		else if (i == 8)
			cout << "W: up";
		else if (i == 9)
			cout << "S: down";
		//else if(i==10)
		//	cout << "snake of length: " << snake.countList();
		cout << endl;
	}
}
//控制窗口-右键点击上边框，属性 - 布局 -  窗口高度
void Wall::setWall(int x, int y, char c)
{
	gameArray[x][y] = c;
}

char Wall::getWall(int x, int y)
{
	return gameArray[x][y];
}

