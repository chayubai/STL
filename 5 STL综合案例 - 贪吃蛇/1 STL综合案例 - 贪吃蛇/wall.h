//#pragma once
#ifndef _WALL_HEAD
#define _WALL_HEAD
#include <iostream>
using namespace std;
//#include "snake.h"

class Wall {
public:
	enum {
		ROW = 26,//��
		COL = 26//��
	};
	//��ʼ��ǽ��
	void initWall();
	//չʾǽ��
	void draw();
	//������������ ��ά����������ݣ����������ߵ�λ�úͳ���
	void setWall(int x, int y, char c);
	//����������ȡ ��ǰλ�õķ��ţ����������ߵ�λ�úͳ���
	char getWall(int x, int y);

	//��ʾ�ߵĳ��� - �������⣬�´ν����ʵ��
	/*Snake& snake;
	Wall(Snake& tempSnake);*/

private:
	char gameArray[ROW][COL];
};
#endif // !_WALL_HEAD
