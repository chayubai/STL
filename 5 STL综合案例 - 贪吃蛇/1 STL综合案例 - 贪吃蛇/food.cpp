#define _CRT_SECURE_NO_WARNINGS 1
#include "food.h"

#include <Windows.h>
//���ù���λ��
void gotoXY_2(HANDLE hOut_2, int x, int y)
{
	COORD pos;
	pos.X = x;//������
	pos.Y = y;//������
	SetConsoleCursorPosition(hOut_2, pos);
}
HANDLE hOut_2 = GetStdHandle(STD_OUTPUT_HANDLE);//������ʾ���������
//ע�⣺��ά����ǽ������ϵ�ǣ�����Ϊx�ᣬ����Ϊy��
//����������ϵ�ǣ�����Ϊy�ᣬ����Ϊx��
//����������Ϊ=/@���ŵ�λ�ã�����λ����ڸ�λ�ò����ö�Ӧ�ķ���=/@

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
			gotoXY_2(hOut_2, foodY * 2, foodX);//��λ
			cout << "#";//���λ������Ϊ#
			break;
		}
	}
}
