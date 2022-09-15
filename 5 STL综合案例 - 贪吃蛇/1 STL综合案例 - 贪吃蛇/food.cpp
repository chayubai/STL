#define _CRT_SECURE_NO_WARNINGS 1
#include "food.h"

#include <Windows.h>
//设置光标的位置
void gotoXY_2(HANDLE hOut_2, int x, int y)
{
	COORD pos;
	pos.X = x;//横坐标
	pos.Y = y;//纵坐标
	SetConsoleCursorPosition(hOut_2, pos);
}
HANDLE hOut_2 = GetStdHandle(STD_OUTPUT_HANDLE);//定义显示器句柄变量
//注意：二维数组墙的坐标系是，向下为x轴，向右为y轴
//而光标的坐标系是，向下为y轴，向右为x轴
//将所有设置为=/@符号的位置，都定位光标在该位置并设置对应的符号=/@

//保证拿到main函数中的同一个wall
Food::Food(Wall& tempWall) :wall(tempWall)
{
}

void Food::setFood()
{
	while (true) {
		//保证随机生成的点处于墙内
		foodX = rand() % (Wall::ROW - 2) + 1;
		foodY = rand() % (Wall::COL - 2) + 1;

		//如果随机的位置是蛇头或蛇身 就重新生成随机数，判断只要是空位置就设置食物 - 反向思维
		if (wall.getWall(foodX, foodY) == ' ') //这里需要使用Wall类中的内容，使用Wall&wall维护墙中的wall
		{
			wall.setWall(foodX, foodY, '#');
			gotoXY_2(hOut_2, foodY * 2, foodX);//定位
			cout << "#";//光标位置设置为#
			break;
		}
	}
}
