#pragma once
#include <iostream>
using namespace std;
#include "wall.h"
class Food {
public:
	int foodX, foodY;
	
	//����ʳ��
	void setFood();
	Wall& wall;//������ά��wall����������ʳ��
	Food(Wall& temp);
};
