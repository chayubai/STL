#define _CRT_SECURE_NO_WARNINGS 1
#include "food.h"

#include <Windows.h>

//��֤�õ�main�����е�ͬһ��wall
Food::Food(Wall& tempWall) :wall(tempWall)
{
}

void Food::setFood()
{
	while (true) {
		//��֤������ɵĵ㴦��ǽ��
		foodX = rand() % (Wall::ROW - 2) + 1;
		foodY = rand() % (Wall::COL - 2) + 1;

		//��������λ������ͷ������ ������������������ж�ֻҪ�ǿ�λ�þ�����ʳ�� - ����˼ά
		if (wall.getWall(foodX, foodY) == ' ') //������Ҫʹ��Wall���е����ݣ�ʹ��Wall&wallά��ǽ�е�wall
		{
			wall.setWall(foodX, foodY, '#');

			break;
		}
	}
}
