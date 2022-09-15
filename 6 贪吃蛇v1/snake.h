//snake.h
#pragma once
#include <iostream>
#include "wall.h"
#include "food.h"
using namespace std;

//�ߵ����ʹ�ô�ͷ����ʵ��
class Snake {
public:

	//�ڵ�
	struct Point {
		//������
		int x, y;
		//ָ����
		Point* next;
	};
	
	//��ʼ���ߵ�����
	void initSnake();

	//��ӽڵ㣬���������ʼ���ߣ�������������ߵĳ���
	void addPoint(int x, int y);

	//���ٽڵ㣬������Ϸ����Ҫ������
	void destroyPoint();
	
	Point* pHead;//�ߵ�ͷ���

	//Snake();
	//Snake(Wall& tempWall);
	Snake(Wall& tempWall, Food& tempFood);

	Wall& wall;//������ά��wall�����ڳ�ʼ��������

	//ɾ���ڵ� - �����ƶ���ʱ��ͷ���Ҫǰ��һ����β�ڵ�Ҫɾ��
	void delPoint();

	enum {
		UP = 'w', DOWN = 's', LEFT = 'a', RIGHT = 'd'
	};

	//�ƶ��ߣ�����ֵ�����ƶ��Ƿ�ɹ���ײǽ(������)�ƶ�ʧ�ܡ�����key���������ƶ��ķ���
	bool move(char key);

	Food& food;//������ά��food����������ʳ��

	bool isRool;//�ж�ͷ���Ƿ�����β������ѭ���ı�ʶ

	//�趨�Ѷ�
	//��ȡˢ��ʱ��
	int getSleepTime();
	//��ȡ�ߵ���� ������ͷ
	int countList();
	//��ȡ���� - ���ݳԵ�ʳ���ȡ������
	int getScore();
	//������������ߵĳ��ȣ�����ǽ���Ҳ࣬�����ʵ�֣�
};
