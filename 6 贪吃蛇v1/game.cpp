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
	//1������ǽ���еĹ���
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
	food.setFood();//һ��ʼҪ����ʳ��
	Snake snake(wall, food);
	snake.initSnake();
	wall.draw();
	
	//�����û�����
	char key = _getch();//ͷ�ļ���#include <conio.h>

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
	//������ѭ����ÿ���ƶ�����Ҫ������
	//��ײǽ�󣬵�����������wasd�����ܼ�������ǰ������棬�޷�������
	while (true)
	{
		//�����û�����
		char key = _getch();//ͷ�ļ���#include <conio.h>

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

	//�Ƿ�������ʶ
	bool isDead = false;
	//��һ�εķ���
	char preKey = NULL;

	while (!isDead)
	{
		//�����û�����
		char key = _getch();//ͷ�ļ���#include <conio.h>

		//��ֹһ��ʼ���� �����������������ᵼ���Ժ��󣬶����������ƶ�
		/*if (key == snake.LEFT)
		{
			continue;
		}*/
		//�ж�����ǵ�һ�ΰ���������ܼ�����Ϸ��֮����Ϸ�а�����Ըı䷽��
		//�ж���һ���ƶ�����
		if (preKey == NULL && key == snake.LEFT)
		{
			continue;
		}

		//��һ�£�����һ�£�ϣ����ֻ��Ҫ��һ�°�����һֱ��һ�������ƶ�
		do
		{
			//����q��ʱ���������
			//ֻ�����������Ҽ���������������ļ�������Ϊ��һ�ΰ����ķ���
			if (key == snake.UP || key == snake.DOWN || key == snake.LEFT || key == snake.RIGHT) 
			{
				//ͬʱ����Ϸ�Ĺ����в���180���ͷ�ƶ���������Ϸ�������Ӧ�÷�ֹ������ͻ��
				//�жϱ��εİ����Ƿ����ϴγ�ͻ�������ƶ�����Ϊ�ң�����AʱӦ��ʹ����ʧЧ����Ϊ�ϴΰ�������
				if ((key == snake.LEFT && preKey == snake.RIGHT) ||
					(key == snake.RIGHT && preKey == snake.LEFT) ||
					(key == snake.UP && preKey == snake.DOWN) ||
					(key == snake.DOWN && preKey == snake.UP)) 
				{
					key = preKey;//�����˳�ͻ����ʱ����Ϊ�ϴΰ�������
				}
				else
				{
					preKey = key;//(���ǳ�ͻ����)������preKey������ʹ��ֻ�е�һ�ΰ���ΪNULL�������һ�ΰ�������ܼ�����Ϸ
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
				key = preKey;//������������������Ϊ��һ�ΰ�������
			}
			
		} while (!_kbhit());//û�м������뷵���棬_kbhit()��û�м��������ʱ�򷵻�0
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
	//��ǰ��draw����Ҳ��һ�з��� ���ȴ�ӡ������ֻ���ƶ���Ż���ʾ����������
	cout << "Snake of length: " << snake.countList() << "  Score: " << snake.getScore() << "��" << endl;

	//�Ƿ�������ʶ
	bool isDead = false;
	//��һ�εķ���
	char preKey = NULL;

	while (!isDead)
	{
		//�����û�����
		char key = _getch();//ͷ�ļ���#include <conio.h>

		//��ֹһ��ʼ���� �����������������ᵼ���Ժ��󣬶����������ƶ�
		/*if (key == snake.LEFT)
		{
			continue;
		}*/
		//�ж�����ǵ�һ�ΰ���������ܼ�����Ϸ��֮����Ϸ�а�����Ըı䷽��
		//�ж���һ���ƶ�����
		if (preKey == NULL && key == snake.LEFT)
		{
			continue;
		}

		//��һ�£�����һ�£�ϣ����ֻ��Ҫ��һ�°�����һֱ��һ�������ƶ�
		do
		{
			//����q��ʱ���������
			//ֻ�����������Ҽ���������������ļ�������Ϊ��һ�ΰ����ķ���
			if (key == snake.UP || key == snake.DOWN || key == snake.LEFT || key == snake.RIGHT)
			{
				//ͬʱ����Ϸ�Ĺ����в���180���ͷ�ƶ���������Ϸ�������Ӧ�÷�ֹ������ͻ��
				//�жϱ��εİ����Ƿ����ϴγ�ͻ�������ƶ�����Ϊ�ң�����AʱӦ��ʹ����ʧЧ����Ϊ�ϴΰ�������
				if ((key == snake.LEFT && preKey == snake.RIGHT) ||
					(key == snake.RIGHT && preKey == snake.LEFT) ||
					(key == snake.UP && preKey == snake.DOWN) ||
					(key == snake.DOWN && preKey == snake.UP))
				{
					key = preKey;//�����˳�ͻ����ʱ����Ϊ�ϴΰ�������
				}
				else
				{
					preKey = key;//(���ǳ�ͻ����)������preKey������ʹ��ֻ�е�һ�ΰ���ΪNULL�������һ�ΰ�������ܼ�����Ϸ
				}

				if (snake.move(key) == true)
				{
					//��ǰ��draw����Ҳ��һ�з��� ���ȴ�ӡ������ֻ���ƶ���Ż���ʾ����������
					system("cls");
					wall.draw();

					cout << "Snake of length: " << snake.countList() << "  Score: " << snake.getScore() << "��" << endl;

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
				key = preKey;//������������������Ϊ��һ�ΰ�������
			}

		} while (!_kbhit());//û�м������뷵���棬_kbhit()��û�м��������ʱ�򷵻�0
	}
#endif
#if 0//���Թ��
	Wall wall;
	wall.initWall();
	Food food(wall);
	food.setFood();
	Snake snake(wall, food);
	snake.initSnake();
	wall.draw();
	gotoXY(hOut, 10, 5);//��������ǽ��ʱ�򣬶����һ���ո�����ǽ���������൱��*2
	//����ǽ�ϵ�@ͷ������ x*2 y
	//���Թ���@λ�õ������� y*2 x
	//ע�⣺��ά����ǽ������ϵ�ǣ�����Ϊx�ᣬ����Ϊy��
	//����������ϵ�ǣ�����Ϊy�ᣬ����Ϊx��
#endif
	srand((unsigned int)time(NULL));
	Wall wall;
	wall.initWall();
	
	Food food(wall);
	food.setFood();
	Snake snake(wall, food);
	snake.initSnake();

	wall.draw();
	//��ǰ��draw����Ҳ��һ�з��� ���ȴ�ӡ������ֻ���ƶ���Ż���ʾ����������
	cout << "Snake of length: " << snake.countList() << "  Score: " << snake.getScore() << "��" << endl;

	//�Ƿ�������ʶ
	bool isDead = false;
	//��һ�εķ���
	char preKey = NULL;

	while (!isDead)
	{
		//�����û�����
		char key = _getch();//ͷ�ļ���#include <conio.h>

		//��ֹһ��ʼ���� �����������������ᵼ���Ժ��󣬶����������ƶ�
		/*if (key == snake.LEFT)
		{
			continue;
		}*/
		//�ж�����ǵ�һ�ΰ���������ܼ�����Ϸ��֮����Ϸ�а�����Ըı䷽��
		//�ж���һ���ƶ�����
		if (preKey == NULL && key == snake.LEFT)
		{
			continue;
		}

		//��һ�£�����һ�£�ϣ����ֻ��Ҫ��һ�°�����һֱ��һ�������ƶ�
		do
		{
			//����q��ʱ���������
			//ֻ�����������Ҽ���������������ļ�������Ϊ��һ�ΰ����ķ���
			if (key == snake.UP || key == snake.DOWN || key == snake.LEFT || key == snake.RIGHT)
			{
				//ͬʱ����Ϸ�Ĺ����в���180���ͷ�ƶ���������Ϸ�������Ӧ�÷�ֹ������ͻ��
				//�жϱ��εİ����Ƿ����ϴγ�ͻ�������ƶ�����Ϊ�ң�����AʱӦ��ʹ����ʧЧ����Ϊ�ϴΰ�������
				if ((key == snake.LEFT && preKey == snake.RIGHT) ||
					(key == snake.RIGHT && preKey == snake.LEFT) ||
					(key == snake.UP && preKey == snake.DOWN) ||
					(key == snake.DOWN && preKey == snake.UP))
				{
					key = preKey;//�����˳�ͻ����ʱ����Ϊ�ϴΰ�������
				}
				else
				{
					preKey = key;//(���ǳ�ͻ����)������preKey������ʹ��ֻ�е�һ�ΰ���ΪNULL�������һ�ΰ�������ܼ�����Ϸ
				}

				if (snake.move(key) == true)
				{
					//��ǰ��draw����Ҳ��һ�з��� ���ȴ�ӡ������ֻ���ƶ���Ż���ʾ����������
					system("cls");
					wall.draw();

					cout << "Snake of length: " << snake.countList() << "  Score: " << snake.getScore() << "��" << endl;

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
				key = preKey;//������������������Ϊ��һ�ΰ�������
			}

		} while (!_kbhit());//û�м������뷵���棬_kbhit()��û�м��������ʱ�򷵻�0
	}
	return 0;
}
