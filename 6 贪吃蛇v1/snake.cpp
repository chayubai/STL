#define _CRT_SECURE_NO_WARNINGS 1

#include "snake.h"

//��֤�õ�main�����е�ͬһ��wall����ʼ�����е����������ʹ�ò����б�
//Snake::Snake()
//{
//	pHead = NULL;
//}
//Snake::Snake(Wall& tempWall) :wall(tempWall)
//{//ͨ��Wall��Ķ���wall����tempWall,tempWall��ʼ��Snake���е�wall
//	//��Snake���е�wall��Wall��Ķ���wall�����ã�����Snake���wall����Wall��Ķ���wall
//	pHead = NULL;
//}
Snake::Snake(Wall& tempWall, Food& tempFood) :wall(tempWall), food(tempFood)
{
	pHead = NULL;
	isRool = false;
}
//�������еĽڵ�
void Snake::destroyPoint()
{
	Point* pCur = pHead;
	while (pCur != NULL) {//������pHead!= NULLͬ������
		pCur = pHead->next;
		delete pHead;
		pHead = pCur;
	}
}

void Snake::addPoint(int x, int y)
{
	//�����½ڵ�
	Point* newPoint = new Point;
	newPoint->x = x;
	newPoint->y = y;
	newPoint->next = NULL;

	//====@   ====@  @ -> =  =====@
	// ��     =        ->    @ 
	//���ԭ����ͷ��Ϊ�գ����Ϊ����=���µ�ͷ����Ϊͷ@
	if (pHead != NULL) {
		wall.setWall(pHead->x, pHead->y, '=');//������Ҫʹ��Wall���е����ݣ�ʹ��Wall&wallά��ǽ�е�wall
	}
	newPoint->next = pHead;
	pHead = newPoint;//����ͷ��
	wall.setWall(pHead->x, pHead->y, '@');

	// @X   X@   =@
	//ͷ�巨������û�д����������ͷ����������ʹ��һ��ȫ�ֵ�pHeadͷָ�룬
	/*if (pHead == NULL)
	{
		pHead = newPoint;
		wall.setWall(pHead->x, pHead->y, '@');
	}
	else
	{
		pHead->next = newPoint;
		Point* temp = pHead;//��¼ԭͷָ��
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
	//βɾ��ǰ��ָ���˫ָ��
	//�����ڵ����ϲ�ɾ��
	if (pHead == NULL || pHead->next == NULL) {
		return;
	}
	Point* pCur = pHead->next;
	Point* pPre = pHead;
	while (pCur->next != NULL) {
		pCur = pCur->next;
		pPre = pPre->next;
	}
	//��ʱ�ҵ�β�ڵ�pCur��ɾ��
	wall.setWall(pCur->x, pCur->y, ' ');//��������Ϊ��

	delete pCur;//ɾ���ߵ�β�ڵ�
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
	//�ж������һ����������β�ͣ���Ӧ�����������ǵ�������������λ��������
	//�ҵ�β��pCur
	Point* pCur = pHead->next;
	Point* pPre = pHead;
	while (pCur->next != NULL) {
		pPre = pPre->next;
		pCur = pCur->next;
	}
	//��ʱͷ����Ҫ����һ�����ƶ���β�ڵ㣬�����ѭ��
	if (pCur->x == x && pCur->y == y) {
		//����β�ͣ�ѭ�������Ե�β����ʾͷ�������Ե���β��
		isRool = true;
		//����
	}
	else {//ͷ������������λ��
		//�ж��û�����λ���Ƿ�ɹ�
		/*
		if (wall.getWall(x, y) == '*' || wall.getWall(x, y) == '=')
		{
			//��ײǽ��ײ�ϳ���������������ֺ�Ƕ��ǽ�ڻ����壬�Ÿ�������
			//��ײ��ǽ������һ������ǽ
			
			addPoint(x, y);//����һ��
			delPoint();
			system("cls");
			wall.draw();
			
			//gotoXY_1()
			cout << "game over" << endl;
			return false;
		}
		*/
		if (wall.getWall(x, y) == '*')
		{
			//��ײǽ��ײ�ϳ���������������ֺ�Ƕ��ǽ�ڻ����壬�Ÿ�������
			//��ײ��ǽ������һ������ǽ

			addPoint(x, y);//����һ��
			delPoint();
			system("cls");
			wall.draw();
			cout << "Snake of length: " << countList() << "  Score: " << getScore() << "��" << endl;
			cout << "game over" << endl;
			return false;
		}
		else if (wall.getWall(x, y) == '=')
		{
			addPoint(x, y);//����һ��
			//��ײ���Լ���β�����������λ��Ӧ����ʾǶ�����壬��ʾβ��������ǰ��һ������ɾ���ڵ�
			system("cls");
			wall.draw();
			cout << "Snake of length: " << countList() << "  Score: " << getScore() << "��" << endl;
			cout << "GAME OVER��" << endl;
			return false;
		}
	}

	//��������������

	//��һλ����Ч�����Ա任
	//�ƶ��ɹ������֣��Ե�ʳ���û�Ե�ʳ��(��û�Ե�ʳ�����һ���Ե�β��)
	if (wall.getWall(x, y) == '#') {
		addPoint(x, y);
		//��������ʳ��
		food.setFood();//������Ҫʹ��Food���е����ݣ�ʹ��Food&food������ʳ��
	}
	else {
		//δ�Ե�ʳ��
		addPoint(x, y);//��ǰ��һ��
		delPoint();//ɾ��β�ڵ㣬�Ὣͷ����Ϊ��
		//������ѭ��ʱ����ʾͷ�ڵ㣬������ﲻ�������ᵼ��ѭ���ǲ���ʾͷ��
		if (isRool == true) {
			wall.setWall(x, y, '@');
		}
	}
	return true;
}

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
	int size = countList() - 1;//ȥ��ͷ��������ε����Ѷ�
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
	int score = (size - 3) * 100;//ÿ��һ��ʳ���100��
	return score;
}
