#define _CRT_SECURE_NO_WARNINGS 1
#include "food.h"

#include <Windows.h>

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

			break;
		}
	}
}
