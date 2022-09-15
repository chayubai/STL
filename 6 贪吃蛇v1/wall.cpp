#define _CRT_SECURE_NO_WARNINGS 1

#include "wall.h"

void Wall::initWall()
{
	for (int i = 0; i < ROW; ++i) {
		for (int j = 0; j < COL; ++j) {
			//��ǽ��
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
			cout << gameArray[i][j] << " ";//��������һ���ո�ǽ����ʾЧ������
		}
		//��5�п�ʼ����汾��Ϣ
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
//���ƴ���-�Ҽ�����ϱ߿����� - ���� -  ���ڸ߶�
void Wall::setWall(int x, int y, char c)
{
	gameArray[x][y] = c;
}

char Wall::getWall(int x, int y)
{
	return gameArray[x][y];
}

