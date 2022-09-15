#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;
#include "wall.h"
#include "snake.h"
#include "food.h"
#include <ctime>
#include <conio.h>
#include <Windows.h>
int main() {

#if 0
	//1、测试墙类中的功能
	Wall wall;
	wall.initWall();
	wall.setWall(5, 5, '=');
	wall.setWall(5, 6, '=');
	wall.setWall(5, 7, '@');

	wall.draw();

	cout << wall.getWall(0, 0) << endl;
	cout << wall.getWall(5, 5) << endl;
	cout << wall.getWall(5, 7) << endl;
	cout << wall.getWall(1, 1) << endl;
#endif
#if 0
	Wall wall;
	wall.initWall();
	Snake snake(wall);
	snake.initSnake();

	wall.draw();
#endif
#if 0
	srand((unsigned int)time(NULL));
	Wall wall;
	wall.initWall();
	
	Food food(wall);
	food.setFood();
	wall.draw();
#endif
#if 0
	srand((unsigned int)time(NULL));
	Wall wall;
	wall.initWall();
	Snake snake(wall);
	snake.initSnake();
	snake.delPoint();
	wall.draw();
#endif
#if 0
	srand((unsigned int)time(NULL));
	Wall wall;
	wall.initWall();
	Food food(wall);
	food.setFood();
	Snake snake(wall,food);
	snake.initSnake();
	snake.move('w');
	snake.move('w');
	snake.move('a');
	wall.draw();
#endif
#if 0
	srand((unsigned int)time(NULL));
	Wall wall;
	wall.initWall();
	Food food(wall);
	food.setFood();//一开始要设置食物
	Snake snake(wall, food);
	snake.initSnake();
	wall.draw();
	
	//接收用户输入
	char key = _getch();//头文件：#include <conio.h>

	if (snake.move(key) == true)
	{
		system("cls");
		wall.draw();
		Sleep(300);
	}
#endif
#if 0
	srand((unsigned int)time(NULL));
	Wall wall;
	wall.initWall();
	Food food(wall);
	food.setFood();

	Snake snake(wall, food);
	snake.initSnake();
	wall.draw();
	//加入死循环后，每次移动都需要按键。
	//当撞墙后，导致死亡，按wasd键又能继续接着前面的蛇玩，无法死亡。
	while (true)
	{
		//接收用户输入
		char key = _getch();//头文件：#include <conio.h>

		if (snake.move(key) == true)
		{
			system("cls");
			wall.draw();
			Sleep(300);
		}
	}
#endif
#if 0
	srand((unsigned int)time(NULL));
	Wall wall;
	wall.initWall();
	Food food(wall);
	food.setFood();
	Snake snake(wall, food);
	snake.initSnake();
	wall.draw();

	//是否死亡标识
	bool isDead = false;
	//上一次的方向
	char preKey = NULL;

	while (!isDead)
	{
		//接收用户输入
		char key = _getch();//头文件：#include <conio.h>

		//防止一开始按左 就死亡，但是这样会导致以后按左，都不能向左移动
		/*if (key == snake.LEFT)
		{
			continue;
		}*/
		//判断如果是第一次按左键，则不能激活游戏。之后游戏中按左可以改变方向。
		//判断上一次移动方向
		if (preKey == NULL && key == snake.LEFT)
		{
			continue;
		}

		//按一下，才走一下，希望：只需要按一下按键就一直往一个方向移动
		do
		{
			//当按q键时，会出问题
			//只允许上下左右键，当按其他方向的键，设置为上一次按键的方向
			if (key == snake.UP || key == snake.DOWN || key == snake.LEFT || key == snake.RIGHT) 
			{
				//同时在游戏的过程中不能180°掉头移动，否则游戏会结束，应该防止按键冲突。
				//判断本次的按键是否与上次冲突，比如移动方向为右，当按A时应该使本次失效，仍为上次按键方向
				if ((key == snake.LEFT && preKey == snake.RIGHT) ||
					(key == snake.RIGHT && preKey == snake.LEFT) ||
					(key == snake.UP && preKey == snake.DOWN) ||
					(key == snake.DOWN && preKey == snake.UP)) 
				{
					key = preKey;//当按了冲突按键时，仍为上次按键方向
				}
				else
				{
					preKey = key;//(不是冲突按键)，更新preKey，这样使得只有第一次按键为NULL，满足第一次按左键不能激活游戏
				}

				if (snake.move(key) == true)
				{
					system("cls");
					wall.draw();
					Sleep(300);
				}
				else
				{
					isDead = true;
					break;
				}
			}
			else
			{
				key = preKey;//当按了其他按键，都为上一次按键方向
			}
			
		} while (!_kbhit());//没有键盘输入返回真，_kbhit()当没有键盘输入的时候返回0
	}
#endif
#if 0
	srand((unsigned int)time(NULL));
	Wall wall;
	wall.initWall();
	Food food(wall);
	food.setFood();
	Snake snake(wall, food);
	snake.initSnake();
	wall.draw();
	//在前面draw后面也加一行分数 长度打印，否则，只有移动后才会显示分数，长度
	cout << "Snake of length: " << snake.countList() << "  Score: " << snake.getScore() << "分" << endl;

	//是否死亡标识
	bool isDead = false;
	//上一次的方向
	char preKey = NULL;

	while (!isDead)
	{
		//接收用户输入
		char key = _getch();//头文件：#include <conio.h>

		//防止一开始按左 就死亡，但是这样会导致以后按左，都不能向左移动
		/*if (key == snake.LEFT)
		{
			continue;
		}*/
		//判断如果是第一次按左键，则不能激活游戏。之后游戏中按左可以改变方向。
		//判断上一次移动方向
		if (preKey == NULL && key == snake.LEFT)
		{
			continue;
		}

		//按一下，才走一下，希望：只需要按一下按键就一直往一个方向移动
		do
		{
			//当按q键时，会出问题
			//只允许上下左右键，当按其他方向的键，设置为上一次按键的方向
			if (key == snake.UP || key == snake.DOWN || key == snake.LEFT || key == snake.RIGHT)
			{
				//同时在游戏的过程中不能180°掉头移动，否则游戏会结束，应该防止按键冲突。
				//判断本次的按键是否与上次冲突，比如移动方向为右，当按A时应该使本次失效，仍为上次按键方向
				if ((key == snake.LEFT && preKey == snake.RIGHT) ||
					(key == snake.RIGHT && preKey == snake.LEFT) ||
					(key == snake.UP && preKey == snake.DOWN) ||
					(key == snake.DOWN && preKey == snake.UP))
				{
					key = preKey;//当按了冲突按键时，仍为上次按键方向
				}
				else
				{
					preKey = key;//(不是冲突按键)，更新preKey，这样使得只有第一次按键为NULL，满足第一次按左键不能激活游戏
				}

				if (snake.move(key) == true)
				{
					//在前面draw后面也加一行分数 长度打印，否则，只有移动后才会显示分数，长度
					system("cls");
					wall.draw();

					cout << "Snake of length: " << snake.countList() << "  Score: " << snake.getScore() << "分" << endl;

					Sleep(snake.getSleepTime());
				}
				else
				{
					isDead = true;
					break;
				}
			}
			else
			{
				key = preKey;//当按了其他按键，都为上一次按键方向
			}

		} while (!_kbhit());//没有键盘输入返回真，_kbhit()当没有键盘输入的时候返回0
	}
#endif
#if 0//测试光标
	Wall wall;
	wall.initWall();
	Food food(wall);
	food.setFood();
	Snake snake(wall, food);
	snake.initSnake();
	wall.draw();
	gotoXY(hOut, 10, 5);//由于设置墙的时候，多加了一个空格，所有墙的纵坐标相当于*2
	//所以墙上的@头坐标是 x*2 y
	//所以光标的@位置的坐标是 y*2 x
	//注意：二维数组墙的坐标系是，向下为x轴，向右为y轴
	//而光标的坐标系是，向下为y轴，向右为x轴
#endif
	srand((unsigned int)time(NULL));
	Wall wall;
	wall.initWall();
	
	Food food(wall);
	food.setFood();
	Snake snake(wall, food);
	snake.initSnake();

	wall.draw();
	//在前面draw后面也加一行分数 长度打印，否则，只有移动后才会显示分数，长度
	cout << "Snake of length: " << snake.countList() << "  Score: " << snake.getScore() << "分" << endl;

	//是否死亡标识
	bool isDead = false;
	//上一次的方向
	char preKey = NULL;

	while (!isDead)
	{
		//接收用户输入
		char key = _getch();//头文件：#include <conio.h>

		//防止一开始按左 就死亡，但是这样会导致以后按左，都不能向左移动
		/*if (key == snake.LEFT)
		{
			continue;
		}*/
		//判断如果是第一次按左键，则不能激活游戏。之后游戏中按左可以改变方向。
		//判断上一次移动方向
		if (preKey == NULL && key == snake.LEFT)
		{
			continue;
		}

		//按一下，才走一下，希望：只需要按一下按键就一直往一个方向移动
		do
		{
			//当按q键时，会出问题
			//只允许上下左右键，当按其他方向的键，设置为上一次按键的方向
			if (key == snake.UP || key == snake.DOWN || key == snake.LEFT || key == snake.RIGHT)
			{
				//同时在游戏的过程中不能180°掉头移动，否则游戏会结束，应该防止按键冲突。
				//判断本次的按键是否与上次冲突，比如移动方向为右，当按A时应该使本次失效，仍为上次按键方向
				if ((key == snake.LEFT && preKey == snake.RIGHT) ||
					(key == snake.RIGHT && preKey == snake.LEFT) ||
					(key == snake.UP && preKey == snake.DOWN) ||
					(key == snake.DOWN && preKey == snake.UP))
				{
					key = preKey;//当按了冲突按键时，仍为上次按键方向
				}
				else
				{
					preKey = key;//(不是冲突按键)，更新preKey，这样使得只有第一次按键为NULL，满足第一次按左键不能激活游戏
				}

				if (snake.move(key) == true)
				{
					//在前面draw后面也加一行分数 长度打印，否则，只有移动后才会显示分数，长度
					system("cls");
					wall.draw();

					cout << "Snake of length: " << snake.countList() << "  Score: " << snake.getScore() << "分" << endl;

					Sleep(snake.getSleepTime());
				}
				else
				{
					isDead = true;
					break;
				}
			}
			else
			{
				key = preKey;//当按了其他按键，都为上一次按键方向
			}

		} while (!_kbhit());//没有键盘输入返回真，_kbhit()当没有键盘输入的时候返回0
	}
	return 0;
}
