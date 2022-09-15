#define _CRT_SECURE_NO_WARNINGS 1

#include "snake.h"
#include <Windows.h>
void gotoXY_1(HANDLE hOut_1, int x, int y)
{
	COORD pos;
	pos.X = x;//横坐标
	pos.Y = y;//纵坐标
	SetConsoleCursorPosition(hOut_1, pos);
}
HANDLE hOut_1 = GetStdHandle(STD_OUTPUT_HANDLE);//定义显示器句柄变量
//将所有设置为=/@符号的位置，都定位光标在该位置并设置对应的符号=/@

//保证拿到main函数中的同一个wall，初始化类中的其他类对象，使用参数列表
//Snake::Snake()
//{
//	pHead = NULL;
//}
//Snake::Snake(Wall& tempWall) :wall(tempWall)
//{//通过Wall类的对象wall传给tempWall,tempWall初始化Snake类中的wall
//	//而Snake类中的wall是Wall类的对象wall的引用，所有Snake类的wall就是Wall类的对象wall
//	pHead = NULL;
//}
Snake::Snake(Wall& tempWall, Food& tempFood) :wall(tempWall), food(tempFood)
{
	pHead = NULL;
	isRool = false;
}
//销毁所有的节点
void Snake::destroyPoint()
{
	Point* pCur = pHead;
	while (pCur != NULL) {//这里用pHead!= NULL同样可以
		pCur = pHead->next;
		delete pHead;
		pHead = pCur;
	}
}

void Snake::addPoint(int x, int y)
{
	//创建新节点
	Point* newPoint = new Point;
	newPoint->x = x;
	newPoint->y = y;
	newPoint->next = NULL;

	//====@   ====@  @ -> =  =====@
	// 空     =        ->    @ 
	//如果原来的头不为空，则改为身子=，新的头结点改为头@
	if (pHead != NULL) {
		wall.setWall(pHead->x, pHead->y, '=');//这里需要使用Wall类中的内容，使用Wall&wall维护墙中的wall
		gotoXY_1(hOut_1, pHead->y * 2, pHead->x);//定位
		cout << "=";//光标位置设置为=
	}
	newPoint->next = pHead;
	pHead = newPoint;//更新头部
	wall.setWall(pHead->x, pHead->y, '@');
	gotoXY_1(hOut_1, pHead->y * 2, pHead->x);
	cout << "@";//光标位置设置为@

	// @X   X@   =@
	//头插法，这里没有传蛇这个链表头参数，而是使用一个全局的pHead头指针，
	/*if (pHead == NULL)
	{
		pHead = newPoint;
		wall.setWall(pHead->x, pHead->y, '@');
	}
	else
	{
		pHead->next = newPoint;
		Point* temp = pHead;//记录原头指针
		pHead = newPoint;
		
		wall.setWall(pHead->x, pHead->y, '@');
		wall.setWall(temp->x, temp->y, '=');
	}*/
}

void Snake::initSnake()
{
	destroyPoint();
	addPoint(5, 3);
	addPoint(5, 4);
	addPoint(5, 5);
}

void Snake::delPoint()
{
	//尾删：前后指针或双指针
	//两个节点以上才删除
	if (pHead == NULL || pHead->next == NULL) {
		return;
	}
	Point* pCur = pHead->next;
	Point* pPre = pHead;
	while (pCur->next != NULL) {
		pCur = pCur->next;
		pPre = pPre->next;
	}
	//此时找到尾节点pCur，删除
	wall.setWall(pCur->x, pCur->y, ' ');//设置区域为空
	gotoXY_1(hOut_1, pCur->y * 2, pCur->x);
	cout << ' ';//光标位置设置为空

	delete pCur;//删除蛇的尾节点
	pCur = NULL;
	pPre->next = NULL;

	//       prev
	//       cur
	//       =      =      =      =
	//       prev   cur
	//       =      =      =      =
	//                     prev   cur
	//       =      =      =      =
	/*Point* pCur = pHead;
	Point* pPre = pCur;
	while (pCur->next != NULL)
	{
		pCur = pCur->next;
		pPre = pCur;
	}
	wall.setWall(pCur->x, pCur->y, ' ');
	delete pCur;
	pCur = NULL;
	pPre = NULL;*/
}

bool Snake::move(char key)
{
	int x = pHead->x;
	int y = pHead->y;
	switch (key) 
	{
		case UP:
			x--;
			break;
		case DOWN:
			x++;
			break;
		case LEFT:
			y--;
			break;
		case RIGHT:
			y++;
			break;
		default:
			break;
	}
	//判断如果下一步碰到的是尾巴，不应该死亡，但是当碰到身体其他位置则死亡
	//找到尾巴pCur
	Point* pCur = pHead->next;
	Point* pPre = pHead;
	while (pCur->next != NULL) {
		pPre = pPre->next;
		pCur = pCur->next;
	}
	//此时头部将要（下一步）移动到尾节点，则进行循环
	if (pCur->x == x && pCur->y == y) {//尾部==头部
		//碰到尾巴，循环，即吃掉尾部显示头部，即吃到了尾部
		isRool = true;
		//继续
	}
	else {//头部碰到其他的位置
		//判断用户到达位置是否成功
		/*
		if (wall.getWall(x, y) == '*' || wall.getWall(x, y) == '=')
		{
			//当撞墙或撞上除身体外的其他部分后，嵌入墙内或身体，才更象死亡
			//当撞到墙，多走一步进入墙
			
			addPoint(x, y);//多走一步
			delPoint();
			system("cls");
			wall.draw();
			
			//gotoXY_1()
			cout << "GAME OVER！" << endl;
			return false;
		}
		*/
		if (wall.getWall(x, y) == '*')
		{
			//当撞墙或撞上除身体外的其他部分后，嵌入墙内或身体，才更象死亡
			//当撞到墙，多走一步进入墙

			addPoint(x, y);//多走一步
			delPoint();
			system("cls");
			wall.draw();
			cout << "Snake of length: " << countList() << "  Score: " << getScore() << "分" << endl;
			cout << "GAME OVER！" << endl;
			return false;
		}
		else if (wall.getWall(x, y) == '=')
		{
			addPoint(x, y);//多走一步
			//当撞到自己除尾巴外的其他部位，应当显示嵌入身体，显示尾部，即向前多一步但不删除节点
			system("cls");
			wall.draw();
			cout << "Snake of length: " << countList() << "  Score: " << getScore() << "分" << endl;
			cout << "GAME OVER！" << endl;
			return false;
		}
	}

	//继续，来到这里

	//下一位置有效，可以变换
	//移动成功分两种，吃到食物和没吃到食物(或没吃到食物，但下一步吃到尾巴)
	if (wall.getWall(x, y) == '#') {
		addPoint(x, y);
		//重新设置食物
		food.setFood();//这里需要使用Food类中的内容，使用Food&food来设置食物
	}
	else {
		//未吃到食物
		addPoint(x, y);//往前走一步
		delPoint();//删除尾节点，会将头设置为空
		//当构成循环时，显示头节点，如果这里不做处理，会导致循环是不显示头部
		if (isRool == true) {
			wall.setWall(x, y, '@');
			gotoXY_1(hOut_1, y * 2, x);
			cout << "@";//光标位置设置为@
		}
	}
	return true;
}
//注意：这里面使用了光标定位，和在光标位置设置值后，是为了给用户看的
//对于如果wall.setWall(X, Y, 'N');对于该案例没有作用。
//但如果日后想要保存游戏时，可以用于保存数据用
int Snake::countList()
{
	//=====@
	int size = 0;
	Point* curPoint = pHead;
	while (curPoint != NULL)
	{
		size++;
		curPoint = curPoint->next;
	}
	return size;
}

int Snake::getSleepTime()
{
	int sleepTime = 0;
	int size = countList() - 1;//去掉头。根据身段调整难度
	if (size < 5)
	{
		sleepTime = 300;
	}
	else if (size >= 5 && size <= 8)
	{
		sleepTime = 200;
	}
	else
	{
		sleepTime = 100;
	}
	return sleepTime;
}

int Snake::getScore()
{
	int size = countList();
	int score = (size - 3) * 100;//每吃一个食物，加100分
	return score;
}
